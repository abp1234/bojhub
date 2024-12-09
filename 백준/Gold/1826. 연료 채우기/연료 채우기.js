const fs = require('fs');

const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
const N = parseInt(input[0]);
const oils = input.slice(1,N+1).map(line =>{
    const [dist,fuel] =line.split(' ').map(Number);
    return {dist,fuel};
});

oils.sort((a,b)=>a.dist-b.dist||b.fuel-a.fuel);

const [L,P]=input[N+1].split(' ').map(Number);

class MaxHeap{
    constructor(){
        this.data = [];
    }

    push(val){
        this.data.push(val);
        let idx = this.data.length - 1;
        while(idx>0){
            const parent = Math.floor((idx-1)/2);
            if(this.data[parent]>=this.data[idx])break;
            [this.data[parent], this.data[idx]]=[this.data[idx], this.data[parent]];
            idx=parent;
        }
    }

    pop(){
        if(this.data.length===0)return null;
        if(this.data.length===1)return this.data.pop();

        const root = this.data[0];
        this.data[0] = this.data.pop();

        let idx = 0;
        while(true){
            const left = 2 * idx + 1;
            const right = 2 * idx + 2;
            let largest = idx;

            if(left<this.data.length&&this.data[left]>this.data[largest]){
                largest = left;
            }
            if(right<this.data.length&&this.data[right]>this.data[largest]){
                largest=right;
            }
            if(largest===idx)break;

            [this.data[idx],this.data[largest]]=[this.data[largest],this.data[idx]];
            idx = largest;
        }

        return root;
    }
}

const heap = new MaxHeap();
let cnt = 0;
let curFuel = P;
for (let i = 0; i <= N; i++) {
    const dist = i === N ? L : oils[i].dist; 
    const fuel = i === N ? 0 : oils[i].fuel;
  

    while (curFuel < dist) {
      if (heap.data.length === 0) {
        console.log(-1); 
        return;
      }
      curFuel += heap.pop(); 
      cnt++;
    }
  
    heap.push(fuel); 
  }
  

  console.log(cnt);
const fs = require('fs');

// Read input from stdin
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

// Initialize variables

class Deque{
    constructor(){
        this.items={};
        this.frontIndex=0;
        this.backIndex=0;
    }
    isEmpty(){
        return this.frontIndex===this.backIndex;
    }
    addBack(item){
        this.items[this.backIndex]=item;
        this.backIndex++;
    }
    removeFront(){
        if(this.isEmpty()){
            return undefined;
        }
        const item = this.items[this.frontIndex];
        delete this.items[this.frontIndex];
        this.frontIndex++;
        if(this.isEmpty()){
            this.frontIndex=0;
            this.backIndex=0;
        }
        return item;
    }
    peekFront(){
        if(this.isEmpty()){
            return undefined;
        }
        return this.items[this.frontIndex];
    }
}


function main() {
    let N = Number(input[0]);
   
    let check = Array(N).fill(0);
    let A = Array.from({ length: N }, () => []);
    for (let idx = 1; idx < N; idx++) {
        let [u, v] = input[idx].split(' ').map(Number);
        u--; 
        v--; 
        A[u].push(v);
        A[v].push(u);
        check[u]++;
        check[v]++;
    }
    let q=new Deque();
    for(let idx =0;idx<N;idx++){
        if(check[idx]===1){
            check[idx]--;
            q.addBack(idx);
        }
    }
    let boss_who=Array(N).fill(0);
    let answer = 0;
    while(!q.isEmpty()){
        let idx=q.removeFront();
        
        for(const i of A[idx]){
            //if(check[i]>1){
                check[i]--;
                if (check[i] === 1) {
                    q.addBack(i);
                }
                if (boss_who[idx] === 0 && boss_who[i] === 0) {
                    if(check[i]>1){
                       boss_who[i] = 1;
                    }else{
                        boss_who[i]=1;
                    }
                    
                    answer++;
                }
           //}
        }
    }
    console.log(answer);

    process.exit();
}

main();


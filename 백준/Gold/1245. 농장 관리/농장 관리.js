const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];
let N, M;

rl.on('line', function(line){
    input.push(line);
    if(input.length === 1) {
        [N, M] = line.split(' ').map(Number);
    }
    if(input.length === N + 1) {
        rl.close();
    }
}).on('close', function(){
    const arr = input.slice(1).map(line => line.split(' ').map(Number));
    const diry = [0,0,-1,1,1,1,-1,-1];
    const dirx = [-1,1,0,0,-1,1,1,-1];
    let visited = Array.from(Array(N), () => Array(M).fill(0));
    let q = [];
    let cnt = 0;

    for(let i=0; i<N; i++){
        for(let j=0; j<M; j++){
            if(arr[i][j] > 0 && visited[i][j] === 0){
                let flag = 0;
                visited[i][j] = 1;
                q.push([i, j]);
                while(q.length > 0){
                    let [curY, curX] = q.shift();
                    for(let k=0; k<8; k++){
                        let dy = diry[k] + curY;
                        let dx = dirx[k] + curX;
                        if(dy<0 || dx<0 || dy>=N || dx>=M) continue;
                        if(arr[dy][dx] === arr[curY][curX] && visited[dy][dx] === 0){
                            q.push([dy, dx]);
                            visited[dy][dx] = 1;
                        }
                        else if(arr[dy][dx] > arr[curY][curX]){
                            flag = 1;
                        }
                    }
                }
                if(flag === 0) cnt++;
            }
        }
    }
    console.log(cnt);
    process.exit();
});
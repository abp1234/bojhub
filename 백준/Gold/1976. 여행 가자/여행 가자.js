
const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];
let target_tr=[];
let N, M;
let lineCount = 0;
rl.on('line', function(line) {
    if (lineCount === 0) {
        N = parseInt(line);
        lineCount++;
    } else if (lineCount === 1) {
        M = parseInt(line);
        lineCount++;
    } else if (lineCount > 1 && lineCount <= N + 1) {
        input.push(line.split(' ').map(Number));
        lineCount++;
    } else if (lineCount > N + 1) {
        target_tr = line.split(' ').map(Number).map(x => x - 1);
        rl.close();
    }
}).on('close', function() {
    let visited = Array(N).fill(0);
    let q = [];
    let currentTargetIndex = 0;
    

    q.push(target_tr[currentTargetIndex]);
    visited[target_tr[currentTargetIndex]] = 1;
    currentTargetIndex++;
    let end = target_tr[currentTargetIndex];
    while (q.length > 0) {
        let start = q.shift();
        if (end === start) {
            if (currentTargetIndex === target_tr.length-1) {
                console.log('YES');
                process.exit();
            }
            q = [end];
            visited = Array(N).fill(0);
            visited[end] = 1;
            currentTargetIndex++;
            end = target_tr[currentTargetIndex];
            
            continue;
        }

        for (let j = 0; j < N; j++) {
            if (input[start][j] === 1 && visited[j]===0) {
                visited[j] = 1;
                q.push(j);
            }
        }
    }

    console.log('NO');
    process.exit();
});

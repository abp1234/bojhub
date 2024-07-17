const fs = require('fs');

// Read input from stdin
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

// Initialize variables
let A = [];
let L, N, K;


function main() {
    [L, N, K] = input[0].split(' ').map(BigInt);
    A = input[1].split(' ').map(BigInt);
    let answer = [];
    let check = new Map();
    let dir = [-1n, 1n];
    let cnt = 0;
    let start=0;
    for (let idx of A) {
        check.set(idx, 0n);
        answer.push(0);
        cnt++;
        if (cnt === Number(K)) {
            console.log(answer.join('\n'));
            process.exit();
        }
    }

    while (A.length > start) {
        let idx = A[start++];
        for (let i = 0; i < 2; i++) {
            let temp_idx = idx + dir[i];
            if (temp_idx < 0n || temp_idx > L) continue;
            if (check.has(temp_idx)) continue;
            check.set(temp_idx, check.get(idx) + 1n);
            answer.push(Number(check.get(temp_idx)));
            A.push(temp_idx);
            cnt++;
            if (cnt === Number(K)) {
                console.log(answer.join('\n'));
                process.exit();
            }
        }
    }
}

main();

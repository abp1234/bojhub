const fs = require('fs');

// Read input from stdin
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

// Initialize variables
let A = [];
let N;


function main() {
    N = Number(input[0]);
    A = input[1].split(' ').map(Number);
    let answer = [];
    let check = [];
    for (let idx=0;idx<N;idx++) {
        while(check.length>0&&A[N-1-idx]>=check[check.length-1]){
            check.pop();
        }
        if(check.length>0){
            answer.push(check[check.length-1]);
        }else{
            answer.push(-1);
        }
        check.push(A[N-1-idx]);
    }
    console.log(answer.reverse().join(' '));
    process.exit();
}

main();

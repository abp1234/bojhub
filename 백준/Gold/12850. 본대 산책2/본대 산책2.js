const fs = require('fs');

const input = fs.readFileSync('/dev/stdin').toString().trim();
let D = BigInt(parseInt(input));

const MOD = BigInt(1000000007);

let A = [
    [0n, 1n, 0n, 0n, 0n, 1n, 0n, 0n],
    [1n, 0n, 1n, 0n, 0n, 0n, 1n, 0n],
    [0n, 1n, 0n, 1n, 0n, 0n, 1n, 1n],
    [0n, 0n, 1n, 0n, 1n, 0n, 0n, 1n],
    [0n, 0n, 0n, 1n, 0n, 0n, 0n, 1n],
    [1n, 0n, 0n, 0n, 0n, 0n, 1n, 0n],
    [0n, 1n, 1n, 0n, 0n, 1n, 0n, 1n],
    [0n, 0n, 1n, 1n, 1n, 0n, 1n, 0n]
];
let ans = [
    [1n, 0n, 0n, 0n, 0n, 0n, 0n, 0n],
    [0n, 1n, 0n, 0n, 0n, 0n, 0n, 0n],
    [0n, 0n, 1n, 0n, 0n, 0n, 0n, 0n],
    [0n, 0n, 0n, 1n, 0n, 0n, 0n, 0n],
    [0n, 0n, 0n, 0n, 1n, 0n, 0n, 0n],
    [0n, 0n, 0n, 0n, 0n, 1n, 0n, 0n],
    [0n, 0n, 0n, 0n, 0n, 0n, 1n, 0n],
    [0n, 0n, 0n, 0n, 0n, 0n, 0n, 1n]
];

const matrixMultiply = (m1, m2) => {
    const result = Array.from({ length: 8 }, () => Array(8).fill(0n));

    for (let i = 0; i < 8; i++) {
        for (let j = 0; j < 8; j++) {
            for (let k = 0; k < 8; k++) {
                result[i][j] = (result[i][j] + m1[i][k] * m2[k][j]) % MOD;
            }
        }
    }
    return result;
};

while(D>0n){
    if(D%2n ===1n){
        ans = matrixMultiply(ans,A);
    }
    A=matrixMultiply(A,A);
    D = D / 2n;
}


console.log(ans[4][4].toString());
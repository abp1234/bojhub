const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');


const [r, c] = input[0].split(' ').map(Number);


const ba = Array.from({ length: r + 1 }, () => Array(c + 1).fill(0)); 
const ap = Array.from({ length: r + 1 }, () => Array(c + 1).fill(0)); 
const psum1 = Array.from({ length: c + 1 }, () => Array(r + 1).fill(0)); 
const psum2 = Array.from({ length: c + 1 }, () => Array(r + 1).fill(0)); 
const dp = Array.from({ length: r + 1 }, () => Array(c + 1).fill(0)); 


for (let i = 1; i <= r; i++) {
    const line = input[i].split(' ');
    for (let j = 1; j <= c; j++) {
        const cell = line[j - 1];
        const type = cell[0];
        const value = parseInt(cell.slice(1), 10);

        if (type === 'B') ba[i][j] = value;
        else ap[i][j] = value;
    }
}


for (let j = 1; j <= c; j++) {
    for (let i = 1; i <= r; i++) {
        psum1[j][i] = psum1[j][i - 1] + ba[i][j]; 
        psum2[j][i] = psum2[j][i - 1] + ap[i][j]; 
    }
}


const sum = (x, y) => psum1[y][x - 1] + psum2[y][r] - psum2[y][x];


for (let i = 1; i <= r; i++) {
    dp[i][1] = psum2[1][r] - psum2[1][i]; 
}
for (let j = 1; j <= c; j++) {
    dp[1][j] = dp[1][j - 1] + psum2[j][r] - psum2[j][1]; 
}


for (let i = 2; i <= r; i++) {
    for (let j = 2; j <= c; j++) {
      
        dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j - 1]) + sum(i, j);
        dp[i][j] = Math.max(dp[i][j], dp[i - 1][j] - ap[i][j]);
    }
}


console.log(dp[r][c]);

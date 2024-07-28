const fs = require('fs');

const input = fs.readFileSync('/dev/stdin').toString().split('\n');

let n, m, k;
let arr = [];
const big = BigInt(1000000007);
let segtree = [];

function init() {
    for (let i = 0; i < n; i++) {
        segtree[n + i] = BigInt(arr[i]);
    }
    for (let i = n - 1; i >= 1; i--) {
        segtree[i] = (segtree[i << 1] * segtree[i << 1 | 1]) % big;
    }
}

function update(idx, x) {
    segtree[idx + n] = BigInt(x);
    let i = ((idx + n) >> 1);
    for (; i >= 1; i >>= 1) {
        segtree[i] = (segtree[i << 1] * segtree[i << 1 | 1]) % big;
    }
}

function find_x(l, r) {
    l += n;
    r += n;
    let result = BigInt(1);
    while (l < r) {
        if (l & 1) {
            result = (result * segtree[l]) % big;
            l++;
        }
        if (r & 1) {
            r--;
            result = (result * segtree[r]) % big;
        }
        l >>= 1;
        r >>= 1;
    }
    return result;
}

function main() {
    [n, m, k] = input[0].split(' ').map(Number);
    for (let i = 0; i < n; i++) {
        arr.push(Number(input[i + 1]));
    }
    segtree = new Array(2 * n).fill(BigInt(1));
    init();
    let ans = [];
    for (let i = 0; i < m + k; i++) {
        let [cmd, a, b] = input[i + n + 1].split(' ').map(Number);
        if (cmd === 1) {
            update(a - 1, b);
        } else {
            let result = find_x(a - 1, b);
            ans.push(result.toString());
        }
    }
    console.log(ans.join('\n'));
    process.exit();
}

main();

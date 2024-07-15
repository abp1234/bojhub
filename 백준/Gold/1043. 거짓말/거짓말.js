const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N, M;
let true_num = [];
let lineCount = 0;
let parties = [];

function find(a, check) {
    if (check[a] === -1) {
        return -1;
    }
    if (check[a] === a) {
        return a;
    }
    check[a] = find(check[a], check);
    return check[a];
}

function union(a, b, check) {
    let a_boss = find(a, check);
    let b_boss = find(b, check);
    if (a_boss === -1 || b_boss === -1) {
        if(a_boss===-1 && b_boss!=-1){
            propagateChange(b, check);
        }else if(a_boss!=-1&&b_boss===-1){
            propagateChange(a, check);
        }
        return 1;
    }
    if (a_boss === b_boss) {
        return 0;
    } else {
        
        propagateChange2(b, check,a_boss);
        return 1;
    }
}
function propagateChange2(member, check,a_boss) {
    let boss = find(member, check);
    for (let i = 1; i < check.length; i++) {
        if (check[i] === boss) {
            check[i] = a_boss; 
        }
    }
}
function propagateChange(member, check) {
    let boss = find(member, check);
    for (let i = 1; i < check.length; i++) {
        if (check[i] === boss) {
            check[i] = -1; 
        }
    }
}
rl.on('line', function(line) {
    if (lineCount === 0) {
        [N, M] = line.split(' ').map(Number);
        lineCount++;
    } else if (lineCount === 1) {
        true_num = line.split(' ').map(Number);
        lineCount++;
    } else if (lineCount < M + 2) {
        parties.push(line.split(' ').map(Number));
        lineCount++;
    } else {
        rl.close();
    }
}).on('close', function() {
    let check = Array(N + 1).fill(0).map((_, idx) => idx);

    for (let i = 1; i <= true_num[0]; i++) {
        check[true_num[i]] = -1;
    }

    for (let j = 0; j < M; j++) {
        for (let i = 1; i < parties[j][0]; i++) {
            union(parties[j][i], parties[j][i + 1], check);
        }
    }
    for(let i=1;i<N+1;i++){
        if(check[i]!=-1){
            find(check[i],check);
        }
        
    }
    let count = 0;
    for (let j = 0; j < M; j++) {
        let flag = false;
        for (let i = 1; i <= parties[j][0]; i++) {
            if (check[parties[j][i]] === -1) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            count++;
        }
    }
    
    console.log(count);
    process.exit();
});

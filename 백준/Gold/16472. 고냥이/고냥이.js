
const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});
let input=[]
// const fs = require('fs');


// const input = fs.readFileSync('/dev/stdin').toString().split('\n');


let A = [];
let N;


function main() {
    N= parseInt(input[0]);
    A = input[1].split('');
    let answer = 1;
    let max_ans=0;
    let start=0;
    let end = 1;
    let check=Array(26).fill(0);
    let ABC=1;
    // console.log(A)
    check[A[0].charCodeAt(0)-'a'.charCodeAt(0)]=1;
    while(end<A.length){
        if(ABC<N ){
            if(check[A[end].charCodeAt(0)-'a'.charCodeAt(0)]===0){
                ABC++;
            }
            check[A[end].charCodeAt(0)-'a'.charCodeAt(0)]++;
            // console.log(1,answer,start)
            // console.log(check)
        }
        else if(ABC===N && check[A[end].charCodeAt(0)-'a'.charCodeAt(0)]>0){
            
            check[A[end].charCodeAt(0)-'a'.charCodeAt(0)]++;
            // console.log(2,answer,start)
            // console.log(check)
        }
        else if(ABC===N &&check[A[end].charCodeAt(0)-'a'.charCodeAt(0)]===0 ){
            check[A[end].charCodeAt(0)-'a'.charCodeAt(0)]++;
            ABC++;
            while(start<=end&&ABC>N){
                check[A[start].charCodeAt(0)-'a'.charCodeAt(0)]--;
                if(check[A[start].charCodeAt(0)-'a'.charCodeAt(0)]===0){
                    ABC--;
                }
                start++;
                answer--;
            }
        //    console.log(3,answer,start)
        //    console.log(check)
        }
        end++;
        answer++;
        max_ans=Math.max(max_ans,answer)
    }
    console.log(max_ans);
    
    process.exit();
}
let LineCount=0;
rl.on('line',function(line){
    input.push(line);
    LineCount++;
    if(LineCount===2){
        rl.close();
    }
}).on('close',main);
// main();
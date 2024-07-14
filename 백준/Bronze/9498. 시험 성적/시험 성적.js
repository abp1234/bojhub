
const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});


let N;
let lineCount=0;
rl.on('line', function(line) {
    if (lineCount === 0) {
        N = parseInt(line);
        rl.close();
    }
}).on('close', function() {
    if(N>=90){
        console.log('A');
    }
    else if(N>=80){
        console.log('B');
    }
    else if(N>=70){
        console.log('C');
    }
    else if(N>=60){
        console.log('D');
    }
    else{
        console.log('F');
    }    
    process.exit();
});

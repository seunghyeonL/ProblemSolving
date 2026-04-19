const fs = require('fs');
let input = fs.readFileSync('./dev/stdin').toString().trim(); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const N = Number(input)

function sum1toN(N) {
    let result = 0;
    for(let i=1 ; i<=N ; i++) {
        result += i;
    }
    return result;
}

function findDeno(n) {
    let deno = 1;
    while(1) {
        if(sum1toN(deno-1) < n && n <= sum1toN(deno)) break;
        deno++;
    }
    let idx = n-sum1toN(deno-1);
    
    let dir = true;
    if(deno%2 === 1) dir = false;

    if(dir) return `${idx}/${deno+1-idx}`
    else return `${deno+1-idx}/${idx}`    
}

console.log(findDeno(N));
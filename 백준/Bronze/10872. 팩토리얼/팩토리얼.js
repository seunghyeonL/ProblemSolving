const fs = require('fs');
let input = fs.readFileSync(0).toString().trim(); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));
let N = Number(input);

function factorial(N) {
    if(N === 0) return 1;
    return N*factorial(N-1);
}

console.log(factorial(N));
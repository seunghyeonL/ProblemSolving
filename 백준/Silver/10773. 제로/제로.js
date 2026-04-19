const fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const inputs = input.slice(1).map(Number);

const stack = [];

for(let el of inputs) {
    if(el) stack.push(el);
    else stack.pop();
}

console.log(stack.reduce((acc, cur) => acc+cur, 0));
const fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const tests = input.slice(1);

function check(test) {
    const stack = [];
    for(let el of test) {
        if(el === ')' && stack[stack.length-1] === '(') stack.pop();
        else stack.push(el);
    }
    if(stack.length === 0) return 'YES';
    else return 'NO';
}

for(let test of tests) {
    console.log(check(test));
}

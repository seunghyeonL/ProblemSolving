const fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const isBracket = char => {
    if(char === '(' || char === ')' || char === '[' || char === ']') return true;
    else return false;
}

const tests = input.slice(0, -1).map(el => el.split('').filter(isBracket));

const check = (arr) => {
    const stack = [];
    for(let el of arr) {
        if(el === ')' && stack[stack.length-1] === '(') stack.pop();
        else if (el === ']' && stack[stack.length-1] === '[') stack.pop();
        else stack.push(el);
    }
    if(stack.length === 0) return 'yes';
    else return 'no';
}

for(let test of tests) {
    console.log(check(test));
}

const fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const tests = input.slice(0, -1).map(el => el.split(' ').map(Number));

function solve(a, b) {
    if(b%a === 0) return 'factor';
    else if(a%b === 0) return 'multiple';
    else return 'neither';
}

for(let test of tests) {
    console.log(solve(test[0], test[1]));
}

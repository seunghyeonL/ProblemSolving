const fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n')

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

let nums = input.map(el => Number(el))
let result = [];

for(let i=1 ; i<=30 ; i++) {
    if(!nums.includes(i)) result.push(i);
}

console.log(result[0], result[1])
const fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n')

// const readline = require('readline');

// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

let N = Number(input[0]);
let nums = input[1].split(' ').map(el => Number(el));
let v = Number(input[2]);

let result = 0;

nums.forEach(el => {
    if(el === v) result++;
})

console.log(result)
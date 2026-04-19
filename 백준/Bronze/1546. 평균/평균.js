const fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n')

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

let N = Number(input[0]);
let nums = input[1].split(' ').map(el => Number(el));

let max = Math.max(...nums);

let newNums = nums.map(el => el/max*100)

let result = newNums.reduce((acc, cur) => {
    return acc + cur/N
}, 0)

console.log(result)
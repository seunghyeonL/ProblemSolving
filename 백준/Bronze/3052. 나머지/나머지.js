const fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n')

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

let nums = input.map(el => Number(el)%42)

let set = new Set(nums);

console.log(set.size);
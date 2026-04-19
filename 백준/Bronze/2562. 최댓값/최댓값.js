const fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n')

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

let nums = input.map(el => Number(el))

let result = nums.reduce((acc, cur, idx) => {
    if(acc[0] < cur) return [cur, idx+1]
    else return acc
}, [0,0])

console.log(result[0], result[1])
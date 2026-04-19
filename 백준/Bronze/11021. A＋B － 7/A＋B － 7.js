const fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');

const T = Number(input[0])

const tests = input.slice(1).map(el => el.split(' ').map(el => Number(el)))

const result = tests.map((el, idx) => `Case #${idx+1}: ${el[0] + el[1]}`)

for(let el of result) console.log(el)
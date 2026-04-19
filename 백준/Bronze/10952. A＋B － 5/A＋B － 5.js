const fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');

let tests = input.map(el => el.split(' ').map(el => Number(el)));
// console.log(tests)

for(let el of tests.slice(0, -1)) {
    console.log(el[0] + el[1])
}
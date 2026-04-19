const fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');

let tests = input.map(el => el.split(' ').map(el => Number(el)));

for(let el of tests) {
    console.log(el[0] + el[1])
}
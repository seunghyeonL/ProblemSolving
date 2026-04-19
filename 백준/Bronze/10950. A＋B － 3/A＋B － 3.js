const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const T = Number(input[0])

const tests = input.slice(1).map(el => el.split(' ').map(el => Number(el)))

for(let el of tests) {
    console.log(el[0] + el[1])
}

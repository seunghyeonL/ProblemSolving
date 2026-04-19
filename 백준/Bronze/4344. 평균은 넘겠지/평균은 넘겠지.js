const fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const C = Number(input[0]);

const tests = input.slice(1).map(el => el.split(' ').map(el => Number(el)));

const avgs = tests.map(el => {
    return el.slice(1).reduce((acc, cur) => acc+cur)/el[0];
})

const result = tests.map((el, idx) => {
    return el.slice(1).filter(el => el > avgs[idx]).length/el[0]*100;
})

for(let el of result) {
    console.log(`${el.toFixed(3)}%`)
}
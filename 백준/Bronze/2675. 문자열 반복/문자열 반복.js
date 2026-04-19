const fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const T = Number(input[0]);
let tests = input.slice(1).map(el => el.split(' '));

tests = tests.map(el => {
    el[0] = Number(el[0]);
    return el;
})

for(let el of tests) {
    let lineStr = '';
    for(let alpha of el[1]) {
        for(let i=0 ; i<el[0] ; i++ ) {
            lineStr += alpha;
        }
    }
    console.log(lineStr);
}

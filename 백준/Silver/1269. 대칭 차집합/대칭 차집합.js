const fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const [N, M] = input[0].split(' ').map(Number);
const A = input[1].split(' ').map(Number);
const B = input[2].split(' ').map(Number);

const answer = A.concat(B).reduce((acc, cur) => {
    if(acc[cur]) delete acc[cur];
    else acc[cur] = 1;
    return acc;
}, {})

console.log(Object.keys(answer).length);
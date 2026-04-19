const fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

let [N, M] = input[0].split(' ').map(Number);
let A = input.slice(1, 1+N).map(el => el.split(' ').map(Number));
let B = input.slice(1+N).map(el => el.split(' ').map(Number));

let sum = A.map((el1, idx1) => el1.map((el2, idx2) => el2 + B[idx1][idx2]))
for(let el1 of sum) {
    let print = '';
    for(let el2 of el1) print += (el2 + ' ');
    console.log(print.trim())
}
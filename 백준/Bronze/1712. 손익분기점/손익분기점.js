const fs = require('fs');
let input = fs.readFileSync('./dev/stdin').toString().trim();

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

let [A, B, C] = input.split(' ').map(el => Number(el));

let cnt = 0;


let x = Math.floor(A/(C-B))+1

console.log((C>B)?x:-1)

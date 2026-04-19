const fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const N = Number(input[0]);
const dividers = input[1].split(' ').map(Number);

console.log(Math.min(...dividers)*Math.max(...dividers));
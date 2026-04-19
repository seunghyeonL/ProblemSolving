const fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const N = Number(input[0]);
const myCards = input[1].split(' ').map(Number);
const M = Number(input[2]);
const testCards = input[3].split(' ').map(Number);

const myCardSet = new Set(myCards);

const result = [];
for(let card of testCards) {
    if(myCardSet.has(card)) result.push(1);
    else result.push(0);
}

console.log(result.join(' '));
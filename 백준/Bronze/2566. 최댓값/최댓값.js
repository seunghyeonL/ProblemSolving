const fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));
let board = input.map(el => el.split(' ').map(Number));

let result = board.reduce((acc1, cur1, idx1) => {
    let lineResult = cur1.reduce((acc2, cur2, idx2) => {
        if(acc2[0] <= cur2) return [cur2, idx2];
        else return acc2;
    }, [-1, -1]);
    if(acc1[0] <= lineResult[0]) return [lineResult[0], idx1, lineResult[1]];
    else return acc1;

}, [-1, -1, -1])

console.log(`${result[0]}`)
console.log(`${result[1]+1} ${result[2]+1}`)
const fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const [N, M] = input[0].split(' ').map(Number);

const dict = input.slice(1, N+1);

const NameToNum = {};
const NumToName = {};

dict.forEach((el, idx) => {
    NameToNum[el] = idx+1;
    NumToName[idx+1] = el;
})

const result = input.slice(N+1).map(el => {
    if(Number(el)) return NumToName[Number(el)];    
    else return NameToNum[el];
})

console.log(result.join('\n'));
const fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().trim().toUpperCase();

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

let dict = {};

for(let el of input) {
    if(dict[el]) dict[el]++;
    else dict[el] = 1;
}

let double = false;
let result;
let resultCnt = 0;
for(let el of Object.keys(dict)) {
    if(dict[el] > resultCnt) {
        result = el;
        resultCnt = dict[el]
        double = false;
    }
    else if(dict[el] === resultCnt) double = true;

}

if(double) console.log('?')
else console.log(result)
const fs = require('fs');

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

let input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin
const T = input[0];
const tests = input.slice(1).map(el => el.split(' ').map(Number));

function euclidGCD(a, b) {
    while(1) {
        if(a%b === 0) break;
        let tmp = b;
        b = a%b;
        a = tmp;
    }
    return b;
}

function findLCM(a, b) {
    return a*b/euclidGCD(a, b);
};

for(let el of tests) {
    console.log(findLCM(el[0], el[1]));
}
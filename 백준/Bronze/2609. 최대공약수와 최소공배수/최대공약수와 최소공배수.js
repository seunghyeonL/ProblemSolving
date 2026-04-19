const fs = require('fs');
let input = fs.readFileSync(0).toString().trim(); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const [a, b] = input.split(' ').map(Number);

function euclidGCD(a, b) {
    while(1) {
        if(a%b === 0) break;
        let tmp = b;
        b = a%b;
        a = tmp;
    }
    return b;
}

const GCD = euclidGCD(a, b);
const LCM = a*b/GCD;

console.log(GCD);
console.log(LCM);


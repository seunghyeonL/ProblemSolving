const fs = require('fs');
let input = fs.readFileSync(0).toString().trim(); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const N = Number(input);

function isEndNum (num) {
    let sixCnt = 0;
    while(1) {
        let lastDigit = num%10;

        if(lastDigit === 6) sixCnt++;
        else sixCnt = 0;

        if(sixCnt === 3) return true;
        num = (num - lastDigit)/10;
        if(num === 0) return false;
    }
}

let i = 0;
let endNumIdx = 0;
while(endNumIdx < N) {
    if(isEndNum(++i)) endNumIdx++;
}

console.log(i);

const fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().trim();

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));
const N = Number(input)

let result = 0;

for(let i=1 ; i<=N ; i++) {
    if(i === 1000) break;
    let d1, d2, d3;
    d1 = i%10;
    d2 = (i%100 - i%10)/10;
    d3 = (i%1000 - i%100)/100;
    if(d3 === 0) {
        result++;
    }
    else if(d2-d1 === d3-d2) {
        result++
    }
}

console.log(result)
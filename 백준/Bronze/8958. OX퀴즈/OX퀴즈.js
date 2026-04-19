const fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

let N = Number(input[0]);
let tests = input.slice(1).map(el => el.split(''));

function score(arr) {
    let result = 0;
    let cnt = 0;
    for(let el of arr) {
        if(el === 'O') {
            result += ++cnt;
        }
        else cnt = 0;
    }
    return result;
}

for(let el of tests) {
    console.log(score(el))
}

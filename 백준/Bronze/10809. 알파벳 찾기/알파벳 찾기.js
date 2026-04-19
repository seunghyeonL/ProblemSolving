const fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().trim();

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));
const inputStrArr = input.split('');

const alphabetArr = 'abcdefghijklmnopqrstuvwxyz';

let result = ''
for(let el of alphabetArr) {
    result += inputStrArr.indexOf(el) + ' '
}

console.log(result.slice(0,result.length-1))
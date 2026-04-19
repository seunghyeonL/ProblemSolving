const fs = require('fs');
let input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

let N = Number(input[0])
let words = input.slice(1);
let result = 0;

function isGroupWord(word) {
    let now = '';
    let history = {};
    for(let el of word) {
        if(el !== now && history[el]) return false;
        else if(el !== now && !history[el]) {
            now = el;
            history[el] = 1;
        }
        else if(el === now) {
            continue;
        }
    }
    return true;
}
for(let word of words) {    
    if(isGroupWord(word)) result++;
}
console.log(result)
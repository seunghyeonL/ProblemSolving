const fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const N = Number(input[0]);
let sizes = input.slice(1).map(el => el.split(' ').map(Number));

function sizeCompare(a, b) {
    if(a[0] > b[0] && a[1] > b[1]) return '>';
    else if (a[0] < b[0] && a[1] < b[1]) return '<';
    else return '=';
}

const result = sizes.map((size, idx) => {
    return sizes.reduce((acc, cur, idx) => {
        if(sizeCompare(size, cur) === '<') return acc+1;
        else return acc;
    }, 1)
})

console.log(result.join(' '));
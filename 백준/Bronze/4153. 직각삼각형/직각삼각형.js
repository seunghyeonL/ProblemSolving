const fs = require('fs');
const input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

function compare(a, b) {
    if(a <= b) return -1;
    if(a > b) return 1;
}

const triangles = input.slice(0, -1).map(el => el.split(' ').map(Number).sort(compare));

const answer = triangles.map(([a, b, c]) => {
    if(c*c === a*a + b*b) return 'right';
    else return 'wrong';
})

console.log(answer.join('\n'));
const fs = require('fs');
const input = fs.readFileSync(0).toString().trim(); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const [x, y, w, h] = input.split(' ').map(Number);

console.log(Math.min(x, y, w-x, h-y));

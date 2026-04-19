const fs = require('fs');
const input = fs.readFileSync(0).toString().trim() // readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const R = Number(input);

const circleArea1 = (3.141592653589793238 * R * R).toFixed(6);
const circleArea2 = (2 * R * R).toFixed(6);
console.log(circleArea1);
console.log(circleArea2);

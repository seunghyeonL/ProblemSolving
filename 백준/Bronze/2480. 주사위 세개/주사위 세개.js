const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split(' ');


const dices = input.map(el => Number(el));

dices.sort();
let [a, b, c] = dices;

if(a === b && b === c) {
    console.log(10000 + a * 1000);
}
else if(a === b) {
    console.log(1000 + a * 100);
}
else if (b === c) {
    console.log(1000 + b * 100);
}
else {
    console.log(c * 100)
}
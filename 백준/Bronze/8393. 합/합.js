const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim();

const n = Number(input);

let result = 0;

for(let i = 1 ; i <= n ; i++) {
    result += i
}

console.log(result)
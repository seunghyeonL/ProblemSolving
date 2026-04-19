const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim();

const n = Number(input)

for(let i = 1 ; i <= 9 ; i++) {
    console.log(`${n} * ${i} = ${n*i}`)
}

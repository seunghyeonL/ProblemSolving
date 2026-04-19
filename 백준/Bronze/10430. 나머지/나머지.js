let fs = require('fs')
let input = fs.readFileSync('/dev/stdin').toString().trim().split(' ')

let [A, B, C] = input.map(el => Number(el))

console.log((A+B)%C)
console.log(((A%C) + (B%C))%C)
console.log((A*B)%C)
console.log(((A%C) * (B%C))%C)

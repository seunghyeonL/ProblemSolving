let fs = require('fs')
let input = fs.readFileSync('/dev/stdin').toString().trim().split(' ')

let right = [1, 1, 2, 2, 2, 8]

let result = right.map((el, idx) => el - input[idx])

console.log(result.join(' '))
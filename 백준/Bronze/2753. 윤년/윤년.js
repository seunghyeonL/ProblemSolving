let fs = require('fs')
let input = fs.readFileSync('/dev/stdin').toString().trim()

let year = Number(input)

let result = 0
if(year%4 === 0 && year%100 !== 0) result = 1
if(year%400 === 0) result = 1
console.log(result)

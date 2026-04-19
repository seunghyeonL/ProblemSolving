const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split(' ')

let [h, m] = input

m = m-45

if(m < 0) {
    m = m+60
    h = (h == 0) ? 23 : h-1
}

console.log(h, m)
const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let [h, m] = input[0].split(' ').map(el => Number(el))
let t = Number(input[1])

m = m+t

if(m >= 60) {
    let hplus = parseInt(m/60)
    m = m%60
    h = (h + hplus)%24
}

console.log(h, m)
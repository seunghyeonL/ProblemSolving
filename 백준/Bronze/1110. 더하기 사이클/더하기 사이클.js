const fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');

let N = Number(input)
let n = N;
let cnt = 0;


while(1) {
    cnt++;
    let one = n%10;
    let ten = parseInt(n/10);
    let nextOne = (one + ten)%10;

    if(one*10 + nextOne === N) break;
    else n = one*10 + nextOne;
}

console.log(cnt)
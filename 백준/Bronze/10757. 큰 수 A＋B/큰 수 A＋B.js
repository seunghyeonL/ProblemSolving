const fs = require('fs');
let input = fs.readFileSync('./dev/stdin').toString().trim(); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

let [A, B] = input.split(' ');
let Aarr = A.split('').reverse();
let Barr = B.split('').reverse();

function sum(a, b) {
    let idx = 0;
    let carry = 0;
    let result = [];

    while(a[idx] || b[idx] || carry) {
        let aNum = a[idx] ? Number(a[idx]) : 0;
        let bNum = b[idx] ? Number(b[idx]) : 0;
                
        let partSum = aNum + bNum;

        if(carry) {
            partSum += 1;
            carry = 0;
        }

        if(partSum >= 10) {
            carry = 1;
            partSum = partSum%10;
        }

        result.push(partSum);        
        idx++;
    }

    return result.reverse().join('');
}

let result = sum(Aarr, Barr)

for(let i=0 ; i<result.length ; i++) {
    if(result[i] !== '0') {
        result = result.slice(i);
        break;
    }
}

console.log(result);
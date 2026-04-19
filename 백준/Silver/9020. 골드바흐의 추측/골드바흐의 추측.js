const fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

let T = Number(input[0]);
let nums = input.slice(1).map(Number);

function findGP(n) {    
    if(n === 4) return [2, 2];
    let result = [2];

    for(let i=3 ; i<=n ; i+=2) {
        let primeCheck = true;
        for(let el of result) {
            if(i%el === 0) {
                primeCheck = false;
                break;
            }
        }
        if(primeCheck) {        
            result.push(i);    
            if(result.includes(n-i)) return [n-i, i];
        }

    }

    return result;
}

// function findGP(n) {
//     let primeSet = makePrimeSet(n);
//     let isUsed = {};
    
//     let result = [0, 0];
//     primeSet.forEach((el, idx) => {        
//         if(isUsed[el]) return;
//         if(primeSet.includes(n-el)) {
//             result = [el, n-el];
//             isUsed[n-el] = true;
//         }
//     })
//     return result;
// }

for(let el of nums) {
    let [a, b] = findGP(el);
    console.log(a, b)
}



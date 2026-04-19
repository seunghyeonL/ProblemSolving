const fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

let nums = input.slice(0, input.length-1).map(Number);

function isPrime(n) {     
    if(n === 1) return false;
    if(n === 2) return true;
    
    let result = true;   
    if(n%2 === 0) result = false;
    for(let i=3 ; i<=Math.sqrt(n) ; i = i+2) {
        if(n%i === 0) {
            result = false;
            break;
        }
    }
    return result;
}

for(let el of nums) {
    let primeCount = 0;
    for(let i=el+1 ; i<=2*el ; i++) {
        if(isPrime(i)) primeCount++; 
    }
    console.log(primeCount)
}

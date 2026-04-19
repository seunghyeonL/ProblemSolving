const fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

let M = Number(input[0]);
let N = Number(input[1]);
let sumPrime = 0;
let minPrime = 0;


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

for(let i=M ; i<=N ; i++) {
    let thisCheck = isPrime(i);
    if(thisCheck && !minPrime) minPrime = i;
    if(thisCheck) sumPrime += i; 
}

if(!minPrime) console.log(-1);
else {
    console.log(sumPrime);
    console.log(minPrime);
}


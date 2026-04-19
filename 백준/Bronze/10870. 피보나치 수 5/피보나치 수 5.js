const fs = require('fs');
let input = fs.readFileSync(0).toString().trim(); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));
let N = Number(input);

let dp = [0, 1];
function pibo(N) {
    if(dp[N] !== undefined) return dp[N]; 
    dp[N] = pibo(N-2) + pibo(N-1);
    return dp[N];
}

console.log(pibo(N));
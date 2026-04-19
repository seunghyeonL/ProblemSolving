const fs = require('fs');
let input = fs.readFileSync('./dev/stdin').toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

let T = Number(input[0])
let inputs = input.slice(1).map(Number)
let tests = Array.from(new Array(T), x => []);

inputs.forEach((el, idx) => {
    let testIdx = Math.floor(idx/2)
    tests[testIdx].push(el);
})

let dp = Array.from(new Array(15), x => new Array(15))

for(let i=0 ; i<=14 ; i++) {
    dp[0][i] = i;
}

function solve(n, k) {
    if(dp[n][k]) return dp[n][k];

    let result = 0;

    for(let i=1 ; i<=k ; i++) {
        if(!dp[n-1][i]) dp[n-1][i] = solve(n-1, i);
        result += dp[n-1][i];
    }

    return result;
}

for(let el of tests) {
    let [n, k] = el;
    console.log(solve(n, k))
}
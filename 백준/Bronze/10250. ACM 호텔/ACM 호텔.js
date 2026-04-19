const fs = require('fs');
let input = fs.readFileSync('./dev/stdin').toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

let T = Number(input[0])
let tests = input.slice(1).map(el => el.split(' ').map(Number))

function findRoom(test) {
    let [H, W, N] = test;
    let w = N%H !== 0 ? Math.floor(N/H)+1 : Math.floor(N/H); // 몇호인가
    let h = N%H !== 0? N%H : H // 몇층인가

    let d3 = String(h);
    let d12 = (w>=10) ? String(w) : '0' + String(w)

    return d3+d12;
}

for(let el of tests) {
    console.log(findRoom(el))
}
const fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));
let N = Number(input[0]);
let papers = input.slice(1).map(el => el.split(' ').map(Number));

let board = Array.from(new Array(100), x => new Array(100).fill(1));

function cover(paper) {
    for(let i=paper[0] ; i<paper[0]+10 ; i++) {
        for(let j=paper[1] ; j<paper[1]+10 ; j++) {
            board[i][j] = 0;
        }
    }
}

for(let paper of papers) {
    cover(paper);
}

console.log(board.reduce((acc1, cur1) => {
    let lineResult = cur1.reduce((acc2, cur2) => {
        if(!cur2) return acc2+1;
        else return acc2;
    }, 0);
    return acc1 + lineResult;
}, 0))

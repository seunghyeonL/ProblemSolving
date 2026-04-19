const fs = require('fs');
let input = fs.readFileSync(0).toString().trim(); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

let N = Number(input);
let result = 0;

for(let i=1 ; i<N ; i++) {
    let nums = [];
    let tmpi = i;
    while(1) {
        nums.push(tmpi%10);
        tmpi = (tmpi-tmpi%10)/10;
        if(tmpi < 1) break;
    }

    if(N === nums.reduce((acc, cur) => acc+cur , i)) {
        result = i;
        break;
    }
}

console.log(result)

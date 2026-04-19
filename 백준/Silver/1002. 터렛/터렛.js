const fs = require('fs');
const input = fs.readFileSync(0).toString().trim().split('\n'); // readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const T = Number(input[0]);
const tests = input.slice(1).map(el => el.split(' ').map(Number));

function findPossiblePositionNum(test) {
    const [x1, y1, r1, x2, y2, r2] = test;
    const distanceSquare = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    const radiusSumSquare = (r1+r2)*(r1+r2);
    const radiusDiffSquare = (r1-r2)*(r1-r2);
    if(distanceSquare > radiusSumSquare) return 0;
    else if(distanceSquare === radiusSumSquare) return 1;
    else if(distanceSquare < radiusSumSquare && distanceSquare > radiusDiffSquare) return 2;
    else if(distanceSquare === radiusDiffSquare) {
        if(distanceSquare === 0 && radiusDiffSquare === 0 && r1 !== 0) return -1;
        return 1;
    }
    else if(distanceSquare < radiusDiffSquare) return 0;

}

for(let test of tests) {
    console.log(findPossiblePositionNum(test));
}

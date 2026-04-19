const fs = require('fs');
const input = fs.readFileSync(0).toString().trim().split('\n'); // readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const T = Number(input[0]);

function makeTests(input) {
    let tmp = [...input.slice(1).map(el => el.split(' ').map(Number))];
    const tests = [];
    for(let i=0 ; i<T ; i++) {
        let test = tmp.slice(0, tmp[1][0]+2);
        tests.push(test);
        tmp = tmp.slice(tmp[1][0]+2);
    }
    return tests;
}

const tests = makeTests(input);

function solve(test) {
    const start = [test[0][0], test[0][1]];
    const dest = [test[0][2], test[0][3]];

    const planetInfo = test.slice(2);

    const initState = planetInfo.map(el => {
        const [x, y, r] = el;
        const distanceSquare = (x-start[0])*(x-start[0]) + (y-start[1])*(y-start[1]);

        if(distanceSquare < r*r) return 1;
        else return 0;
    })

    const finalState = planetInfo.map(el => {
        const [x, y, r] = el;
        const distanceSquare = (x-dest[0])*(x-dest[0]) + (y-dest[1])*(y-dest[1]);

        if(distanceSquare < r*r) return 1;
        else return 0;
    })

    return finalState.reduce((acc, cur, idx) => {
        if(cur !== initState[idx]) return ++acc;
        else return acc;
    }, 0)
}

for(let test of tests) {
    console.log(solve(test));
}
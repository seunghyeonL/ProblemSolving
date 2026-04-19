const fs = require('fs');
const input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const points = input.map(el => el.split(' ').map(Number));

function makeXMap(points) {    
    return points.reduce((acc, cur) => {
        if(acc[cur[0]]) {
            acc[cur[0]]++;
            return acc;
        }
        else {
            acc[cur[0]] = 1;
            return acc;
        }
    }, {})
}

function makeYMap(points) {
    return points.reduce((acc, cur) => {
        if(acc[cur[1]]) {
            acc[cur[1]]++;
            return acc;
        }
        else {
            acc[cur[1]] = 1;
            return acc;
        }
    }, {})
}

const xMap = makeXMap(points);
const yMap = makeYMap(points);
const xAnswer = Object.keys(xMap).reduce((acc, cur) => {
    if(xMap[cur]%2 !== 0) return cur;
    else return acc;
}, null)

const yAnswer = Object.keys(yMap).reduce((acc, cur) => {
    if(yMap[cur]%2 !== 0) return cur;
    else return acc;
}, null)

console.log(xAnswer, yAnswer);

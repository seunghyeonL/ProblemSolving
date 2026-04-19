const fs = require('fs');
const input = fs.readFileSync(0).toString().trim().split('\n'); // readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));

const K = Number(input[0]);
const figureInfo = input.slice(1).map(el => el.split(' ').map(Number));

function findBigArea(arr) {
    const dirLength = {};
    let result = [];

    for(let el of arr) {
        const dir = el[0];
        const len = el[1];

        if(!dirLength[dir]) dirLength[dir] = [len];            
        else dirLength[dir].push(len);
    }

    for(let el of Object.keys(dirLength)) {
        if(dirLength[el].length === 1) result.push(dirLength[el])
    }

    return result[0]*result[1];
} 

function findSmallArea(arr) {
    const nextDirObj = {
        1 : 4, 
        4 : 2,
        2 : 3,
        3 : 1
    }
    let curDir = arr[0][0];
    for(let i=0 ; i<arr.length; i++) {
        let newDir = i+1 < arr.length ? arr[i+1][0] : arr[0][0];

        if(nextDirObj[curDir] !== newDir) return i+1 < arr.length ? arr[i][1] * arr[i+1][1] : arr[i][1] * arr[0][1];    

        curDir = newDir;
    }
}

// 1 4 2 3 1

console.log((findBigArea(figureInfo)-findSmallArea(figureInfo))*K);
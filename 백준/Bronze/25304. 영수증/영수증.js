const fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');

const cost = Number(input[0]);
const N = Number(input[1]);

const records = input.slice(2).map(el => el.split(' ').map(el => Number(el)));

const sum = records.reduce((acc, cur) => {
    return acc + cur[0]*cur[1];
}, 0)

if(sum === cost) console.log('Yes')
else console.log('No')

const fs = require('fs');
const input = fs.readFileSync('./dev/stdin').toString().trim().split('\n')

let N = Number(input[0]);
let nums = input[1].split(' ').map(el => Number(el));
nums = nums.sort((a, b) => {
    if(a <= b) return -1;
    else return 1
});

console.log(nums[0], nums[nums.length-1])
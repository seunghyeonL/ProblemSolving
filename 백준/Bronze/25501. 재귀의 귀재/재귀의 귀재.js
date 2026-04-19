const fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));
let T = Number(input[0]);
let words = input.slice(1)

function recursion(str, l, r, cnt) {
    cnt++;
    if(l >= r) return [1, cnt];
    else if (str[l] !== str[r]) return [0, cnt];
    else return recursion(str, l+1, r-1, cnt);
}

function isPalindrome(str) {
    return recursion(str, 0, str.length-1, 0);
}

for(let word of words) {
    let result = isPalindrome(word);
    console.log(result[0], result[1]);
}

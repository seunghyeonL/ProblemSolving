const fs = require('fs');
let input = fs.readFileSync(0).toString().trim().split('\n'); //readFileSync(0) : stdin

// const readline = require('readline');
// const rl = readline.createInterface(fs.createReadStream('./input.txt'));
let [A, K] = input[0].split(' ').map(Number);
let arr = input[1].split(' ').map(Number);
let cnt = 0;

function mergeSort(arr) {
    if(arr.length === 1) return arr;
    let m = Math.ceil(arr.length/2);
    let leftArr = mergeSort(arr.slice(0, m));
    let rightArr = mergeSort(arr.slice(m));
    let result = merge(leftArr, rightArr);

    return result;
}

function merge(arr1, arr2) {
    let leftIdx = 0;
    let rightIdx = 0;

    let m = arr1.length;
    let n = arr2.length;

    let result = [];

    while(leftIdx < m && rightIdx < n) {
        if(arr1[leftIdx] < arr2[rightIdx]) {
            result.push(arr1[leftIdx++]);
            if(++cnt === K) console.log(arr1[leftIdx-1]);
        }
        else {
            result.push(arr2[rightIdx++]);   
            if(++cnt === K) console.log(arr2[rightIdx-1]);
        }      
    }

    while(leftIdx < m) {
        result.push(arr1[leftIdx++]);
        if(++cnt === K) console.log(arr1[leftIdx-1]);
    }
    while(rightIdx < n) {
        result.push(arr2[rightIdx++]);
        if(++cnt === K) console.log(arr2[rightIdx-1]);
    }

    return result;
}

mergeSort(arr);

if(cnt < K) console.log(-1)
let valid = new Array(10001).fill(true); 

for(let i=1 ; i<10000 ; i++) {
    let d1, d2, d3, d4;
    d1 = i%10;
    d2 = (i%100 - i%10)/10;
    d3 = (i%1000 - i%100)/100;
    d4 = (i - i%1000)/1000;

    let next = i + d1 + d2 + d3 + d4;
    valid[next] = false;
}

valid.forEach((el, idx) => {
    if(idx === 0) return;
    if(el) console.log(idx);
})
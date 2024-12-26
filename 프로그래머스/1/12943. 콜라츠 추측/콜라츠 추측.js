function solution(num) {
    var answer = -1;
    // 짝수면 2로 나누고
    // 홀수면 3곱하고 1더하고
    // 500번 반복 단 그전에 1이 되면 탈출
    
    for(let i=0;i<500;i++) {
        if(num === 1) {
            answer = i;
            break;
        }
        if(num%2 === 0) num /= 2;
        else num = num*3+1;      
        
    }
    
    
    return answer;
}
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

long long solution(int w,int h) {
    long long answer = 1;
    
    long long g = gcd(w, h);
    w /= g;
    h /= g;
    
    return g * w * g * h - (w + h - 1) * g;
}
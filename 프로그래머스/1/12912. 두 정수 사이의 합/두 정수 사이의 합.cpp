#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int a, int b) {
    if(a > b) {
        int tmp = b;
        b = a;
        a = tmp;
    }
        
    long long  result = 0;
    for (long long i = a ; i <= b ; i++) {
        result += i;   
    }
    
    return result;
}
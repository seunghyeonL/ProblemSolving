#include <iostream>

using namespace std;
int solution(int n)
{
    int result = 0;
    while(true) {
        if(n == 0) break;
        
        result += n % 10;
        n /= 10;
    }
    return result;
}
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
        
    for (int x = -r2 ; x <= r2 ; ++x)
    {
        int begin = abs(r1) > abs(x) ? ceil(sqrt((long long)r1*r1 - (long long)x*x)) : 0;
        int end = floor(sqrt((long long)r2*r2 - (long long)x*x));
        
        // cout << "begin: " << begin << " end: " << end << '\n';
        
        for (int y = begin; y <= end; ++y)
        {
            answer += 2;
        }
        
        if (begin == 0) 
        {
            answer -= 1;    
        }
    }
    
    return answer;
}
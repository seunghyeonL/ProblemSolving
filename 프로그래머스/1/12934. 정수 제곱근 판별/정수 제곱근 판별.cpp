#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    long long i = 1;
    while (i * i <= n) {
        if (i * i == n) {
            return (i+1) * (i+1);
        }
        i++;
    }
    
    return answer;
}
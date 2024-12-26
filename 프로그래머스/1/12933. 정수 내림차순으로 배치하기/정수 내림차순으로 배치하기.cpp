#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    string strN = to_string(n);
    
    sort(strN.begin(), strN.end(), greater<char>());
    long long answer = stoll(strN);
    return answer;
    
}
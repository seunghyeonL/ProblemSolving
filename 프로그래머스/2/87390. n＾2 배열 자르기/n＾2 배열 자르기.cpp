#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;
    
    for(long long i = left ; i <= right ; i++) {
        long long x = i / n;
        long long y = i % n;
        
        answer.push_back((x < y ? y : x) + 1);
    }
    
    return answer;
}

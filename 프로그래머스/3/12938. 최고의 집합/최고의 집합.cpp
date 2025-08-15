#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if (n > s) return vector<int>{-1};
    
    int m = s / n;
    int r = s % n;
    
    vector<int> answer(n, m);
    
    fill(answer.end() - r,  answer.end(), m + 1);
    
    return answer;
}
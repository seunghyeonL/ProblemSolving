#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    answer = strings;
    
    sort(answer.begin(), answer.end(), [n](auto a, auto b) -> auto {
        return a.at(n) == b.at(n) ? a < b : a.at(n) < b.at(n);    
    });
    
    return answer;
}
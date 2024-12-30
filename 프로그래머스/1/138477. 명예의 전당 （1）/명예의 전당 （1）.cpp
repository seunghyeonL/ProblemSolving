#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    multiset<int, bool(*)(int, int)> ms([](int a, int b) -> bool {return a > b;});

    for (int i = 0 ; i < score.size() ; i++) {
        ms.insert(score[i]);
        auto msBegin = ms.begin();
        if (ms.size() <= k) {
            answer.push_back(*prev(ms.end()));
        } else {
            advance(msBegin, k - 1);
            answer.push_back(*msBegin);
        }
    }
    
    return answer;
}

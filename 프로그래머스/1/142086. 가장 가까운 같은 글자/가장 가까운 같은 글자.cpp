#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    bool found{false};

    for (auto it = s.begin(); it < s.end(); it++) {
        found = false;
        for (auto rIt = it - 1; rIt >= s.begin(); rIt--) {
            if (*rIt == *it) {
                answer.push_back(distance(rIt, it));
                found = true;
                break;
            }
        }
        if (!found) {
            answer.push_back(-1);
        }
    }

    return answer;
}
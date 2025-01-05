#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> sounds{"aya", "ye", "woo", "ma"};

    for (string str : babbling) {
        string prev{""};
        string cur{""};

        for (char c : str) {
            cur += c;
            auto targetIt = find(sounds.begin(), sounds.end(), cur);
            if (targetIt == sounds.end()) {
                continue;
            } else {
                if (cur == prev) {
                    break;
                }
                prev = cur;
                cur = "";
            }
        }
        if (cur.empty()) {
            answer++;
        }
    }

    return answer;
}
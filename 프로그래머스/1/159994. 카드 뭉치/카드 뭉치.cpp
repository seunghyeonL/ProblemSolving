#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2,
                vector<string> goal) {
    string answer = "No";

    int idx1 = 0, idx2 = 0, idxG = 0;

    while (idx1 < cards1.size() || idx2 < cards2.size()) {
        if (goal[idxG] == cards1[idx1]) {
            ++idxG;
            ++idx1;
        } else if (goal[idxG] == cards2[idx2]) {
            ++idxG;
            ++idx2;
        } else {
            break;
        }
        
        if (idxG == goal.size()) {
            answer = "Yes";
            break;
        }
    }

    return answer;
}
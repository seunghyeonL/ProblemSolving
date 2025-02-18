#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(string name) {
    int answer = 0;
    int size = name.size();
    vector<int> moveCost(size, 0);

    for (int i = 0; i < size; i++) {
        if (name[i] != 'A') {
            moveCost[i] = min(name[i] - 'A', 'Z' - name[i] + 1);
        }
    }

    answer += accumulate(moveCost.begin(), moveCost.end(), 0);

    int minMove = size - 1;
    bool changeFlag = false;
    for (int i = 0; i < size; i++) {
        if (name[i] != 'A') {
            changeFlag = true;
            int nextIdx = i + 1;
            while (nextIdx < size && name[nextIdx] == 'A') nextIdx++;
            
            int leftMove = i * 2 + (size - nextIdx);
            int rightMove = (size - nextIdx) * 2 + i;
            minMove = min({minMove, leftMove, rightMove});
        }
    }
    if(changeFlag) answer += minMove;
    return answer;
}
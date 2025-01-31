#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

int solution(vector<int> picks, vector<string> minerals)
{
    int answer = 25 * minerals.size();
    int tmpAnswer = 0;

    vector<unordered_map<string, int>> exhaustionTable{
        {{"diamond", 1}, {"iron", 1}, {"stone", 1}},
        {{"diamond", 5}, {"iron", 1}, {"stone", 1}},
        {{"diamond", 25}, {"iron", 5}, {"stone", 1}}};

    function<void(int)> dfs = [&](int idx) -> void
    {
        // cout << "idx: " << idx << " tmpAnswer: " << tmpAnswer
        //      << " answer: " << answer << '\n';

        for (int pick = 0; pick < 3; pick++)
        {
            if (picks[pick] == 0)
            {
                continue;
            }
            picks[pick]--;
            int cnt = 0;
            int answerDiff = 0;

            while (cnt < 5)
            {
                answerDiff += exhaustionTable[pick][minerals[idx]];
                // cout << "(" << pick << ", " << minerals[idx] << ", "
                //      << exhaustionTable[pick][minerals[idx]] << ") ";
                ++idx;
                ++cnt;

                if (idx == minerals.size())
                {
                    break;
                }
            }
            // cout << '\n';
            // cout << "cnt: " << cnt << " answerDiff: " << answerDiff << '\n';
            tmpAnswer += answerDiff;

            if (idx == minerals.size() ||
                (picks[0] == 0 && picks[1] == 0 && picks[2] == 0))
            {
                // cout << "!!!!!!!!!idx: " << idx << "tmpAnswer: " << tmpAnswer
                //      << '\n';
                if (tmpAnswer < answer)
                    answer = tmpAnswer;
            }
            else
            {
                dfs(idx);
            }

            tmpAnswer -= answerDiff;
            idx -= cnt;
            picks[pick]++;
        }
    };

    dfs(0);

    return answer;
}

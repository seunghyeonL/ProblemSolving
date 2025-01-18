#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>

using namespace std;

int solution(int x, int y, int n)
{
    int answer = -1;
    vector<function<int(int)>> tasks{
        [n](int x) { return x + n; },
        [](int x) { return x * 2; },
        [](int x) { return x * 3; },
    };

    unordered_set<int> s;
    queue<pair<int, int>> q; // value, cnt, task
    q.push({x, 0});

    while (!q.empty())
    {
        auto [curValue, curCnt] = q.front();
        s.insert(curValue);

        if (curValue == y)
        {
            answer = curCnt;
            break;
        }
        q.pop();

        for (auto task : tasks)
        {
            int nextValue = task(curValue);
            if (s.find(nextValue) == s.end()) {
                s.insert(nextValue);
            } else {
                continue;
            }
            
            if (nextValue <= y)
                q.push({nextValue, curCnt + 1});
        }
    }

    return answer;
}

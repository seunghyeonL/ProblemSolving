#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores)
{
    using P = pair<int, int>; // 점수 합, idx
    int answer = -1;
    int size = scores.size();

    for (int i = 0; i < size; i++)
    {
        scores[i].push_back(i);
    }

    auto comp = [&](const auto &a, const auto &b) -> bool
    {
        if (a[0] == b[0])
        {
            return a[1] < b[1];
        }
        else
        {
            return a[0] > b[0];
        }
    };

    sort(scores.begin(), scores.end(), comp);

    vector<P> receivers;

    int cb = -1;
    for (int i = 0; i < size; i++)
    {
        int a = scores[i][0];
        int b = scores[i][1];
        int idx = scores[i][2];

        // cout << a << ' ' << b << '\n';

        if (b >= cb)
            receivers.emplace_back(a + b, idx);

        cb = max(cb, b);
    }

    sort(receivers.begin(), receivers.end(), [](auto a, auto b)
         { return a.first > b.first; });

    int cScoreSum = 200000;
    int cRank = 1;
    int cnt = 0;

    // Printc<vector<P>, Printp<P>> printc;
    // printc(receivers);

    for (auto [s, idx] : receivers)
    {
        cnt++;

        if (cScoreSum != s)
        {
            cScoreSum = s;
            cRank = cnt;
        }

        if (idx == 0)
        {
            answer = cRank;
            break;
        }
    }

    return answer;
}

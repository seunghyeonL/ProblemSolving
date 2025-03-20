#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    vector<vector<int>> S(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> S[i][j];
        }
    }

    vector<bool> teamArr(N, false); // true팀(1팀) , false팀(0팀)
    vector<int> scoreArr(2, 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scoreArr[0] += S[i][j];
        }
    }
    int minScoreDiff = scoreArr[0];

    auto changeTeam = [&](int person)
    {
        bool curTeam = teamArr[person];
        bool nextTeam = !curTeam;

        for (int i = 0; i < N; i++)
        {
            if (i == person)
                continue;

            if (teamArr[i] == curTeam)
            {
                scoreArr[curTeam] -= (S[i][person] + S[person][i]);
            }

            if (teamArr[i] == nextTeam)
            {
                scoreArr[nextTeam] += S[i][person] + S[person][i];
            }
        }

        teamArr[person] = nextTeam;
    };

    function<void(int, int)> run = [&](int idx, int depth) -> void
    {
        int localScoreDiff = scoreArr[0] - scoreArr[1];
        if (depth == N/2 || localScoreDiff < 0)
        {
            minScoreDiff = min(minScoreDiff, abs(localScoreDiff));
            return;
        }

        if (idx >= N)
        {
            return;
        }
        
        for (int i = idx; i < N; i++)
        {
            changeTeam(i);
            run(i + 1, depth + 1);
            changeTeam(i);
        }
    };

    run(0, 0);

    cout << minScoreDiff;

    return 0;
}
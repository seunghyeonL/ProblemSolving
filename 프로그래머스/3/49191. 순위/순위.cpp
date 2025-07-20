#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> results)
{
    int answer = 0;

    // 단방향 연결리스트 2개
    vector<vector<int>> winAdj(n + 1);  // 내가 이긴놈 연결
    vector<vector<int>> loseAdj(n + 1); // 나를 이긴놈 연결

    for (auto result : results)
    {
        int winner = result[0];
        int loser = result[1];

        winAdj[winner].push_back(loser);
        loseAdj[loser].push_back(winner);
    }

    vector<int> visited(n + 1);

    function<int(int)> getWinClusterSize = [&](int player)
    {
        int result = 1;
        visited[player] = 1;
        for (int loserForMe : winAdj[player])
        {
            if (!visited[loserForMe])
            {
                result += getWinClusterSize(loserForMe);
            }
        }

        return result;
    };

    function<int(int)> getLoseClusterSize = [&](int player)
    {
        int result = 1;
        visited[player] = 1;
        for (int winnerForMe : loseAdj[player])
        {
            if (!visited[winnerForMe])
            {
                result += getLoseClusterSize(winnerForMe);
            }
        }

        return result;
    };

    for (int i = 1; i <= n; i++)
    {
        int winSize = getWinClusterSize(i) - 1;
        fill(visited.begin(), visited.end(), 0);
        int loseSize = getLoseClusterSize(i) - 1;
        fill(visited.begin(), visited.end(), 0);

        if (winSize + loseSize == n - 1)
        {
            answer++;
        }
    }


    return answer;
}
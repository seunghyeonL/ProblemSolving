#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> results)
{
    int answer = 0;

    vector<vector<int>> winTable(n + 1, vector<int>(n + 1, 0));

    for (auto result : results)
    {
        int winner = result[0];
        int loser = result[1];

        winTable[winner][loser] = 1;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (winTable[i][k] && winTable[k][j])
                    winTable[i][j] = 1;

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (winTable[i][j] || winTable[j][i])
                cnt++;
        }
        if (cnt == n - 1)
            answer++;
    }

    return answer;
}

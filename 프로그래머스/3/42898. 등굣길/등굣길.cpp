#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles)
{
    using ll = long long;

    vector<vector<int>> board(m + 1, vector<int>(n + 1, 0));
    vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, 0));

    // 웅덩이는 1로 표시
    for (auto puddle : puddles)
    {
        int x = puddle[0];
        int y = puddle[1];

        board[x][y] = 1;
    }

    dp[1][1] = 1;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
                continue;

            if (board[i][j])
                continue;

            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
        }
    }

    return dp[m][n] % 1000000007;
}

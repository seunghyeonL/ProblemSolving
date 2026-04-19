#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        dp
        i, j 를 우측 하단으로 하는 최대 정사각형 길이 저장

        i, j가 1일때
        => dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1

        아니면
        => dp[i][j] = 0
    */

    int n, m;
    cin >> n >> m;

    vector<string> board(n);
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = board[0][0] == '1';

    int res = dp[0][0];

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = board[i][0] == '1';
        res = max(res, dp[i][0]);
    }

    for (int i = 1; i < m; i++)
    {
        dp[0][i] = board[0][i] == '1';
        res = max(res, dp[0][i]);
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (board[i][j] == '1')
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            else
                dp[i][j] = 0;

            res = max(res, dp[i][j]);
        }
    }

    cout << res * res << '\n';

    // inputFileStream.close();
    return 0;
}


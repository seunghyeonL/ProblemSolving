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
        LCS DP
    */

    string s1, s2;
    cin >> s1 >> s2;

    int N = s1.size();
    int M = s2.size();

    // dp[i][j] : s1[0, i), s2[0, j)의 LCS
    vector<vector<int>> dp(N + 1, vector<int>(M + 1));

    /*
        s1[i - 1] == s2[j - 1]
        => dp[i][j] = dp[i - 1][j - 1] + 1

        else
        => dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    */

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[N][M] << '\n';

    // inputFileStream.close();
    return 0;
}

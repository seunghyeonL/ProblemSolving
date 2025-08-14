#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int N, K;
    cin >> N >> K;

    vector<int> w(N + 1);
    vector<int> v(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> w[i] >> v[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0)); // dp[i][j] : i번째 물건까지 보고, 허용 무게가 j일때 최대 가치
    // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i])

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (j < w[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }

    cout << dp[N][K];

    // inputFileStream.close();
    return 0;
}
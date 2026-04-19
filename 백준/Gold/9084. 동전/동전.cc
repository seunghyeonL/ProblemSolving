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
        동전 DP
    */

    int T;
    cin >> T;

    for (int _ = 0; _ < T; _++)
    {
        int N;
        cin >> N;

        vector<int> coins(N);

        for (int i = 0; i < N; i++)
        {
            cin >> coins[i];
        }

        int M;
        cin >> M;

        // dp[i] : i원을 만드는 경우의 수
        vector<int> dp(M + 1);
        dp[0] = 1;

        for (int coin : coins)
        {
            for (int i = coin; i <= M; i++)
            {
                dp[i] += dp[i - coin];
            }
        }

        cout << dp[M] << '\n';
    }

    // inputFileStream.close();
    return 0;
}

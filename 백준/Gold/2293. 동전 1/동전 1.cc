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
    */

    int N, K;
    cin >> N >> K;

    vector<int> coins(N);

    for (int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }

    // dp[i] : i원을 만드는 동전 최소 개수
    vector<int> dp(K + 1, 0);
    dp[0] = 1; // 아무것도 안쓰기

    for (int coin : coins)
    {
        for (int i = coin; i <= K; i++)
        {
            dp[i] += dp[i - coin];
        }
    }

    cout << dp[K] << '\n';

    // inputFileStream.close();
    return 0;
}

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
    vector<int> dp(K + 1, 1e9);
    dp[0] = 0; // 아무것도 안쓰기

    for (int i = 1; i <= K; i++)
    {
        for (int coin : coins)
        {
            if (i >= coin)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    cout << (dp[K] == 1e9 ? -1 : dp[K]) << '\n';

    // inputFileStream.close();
    return 0;
}
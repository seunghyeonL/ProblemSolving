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

    vector<int> dp(K + 1, 0); // dp[j] : 허용 무게 i인 가방의 최대 가치
    // dp[j] = max(dp[j], dp[j - w[i]] + v[i])

    for (int i = 1; i <= N; i++)
    {
        for (int j = K; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[K];

    // inputFileStream.close();
    return 0;
}
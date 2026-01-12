#include <bits/stdc++.h>
using namespace std;

constexpr int LMX = 50;

int N, K;
vector<string> arr;
vector<int> num_mode;
vector<int> digit_mode(LMX + 1);

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");
    using ll = long long;

    cin >> N;
    arr.resize(N);
    num_mode.resize(N);

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cin >> K;

    digit_mode[0] = 1;
    for (int i = 1; i <= LMX; i++)
    {
        digit_mode[i] = (digit_mode[i - 1] * 10) % K;
    }

    for (int i = 0; i < N; i++)
    {
        string &num = arr[i];

        int cur = 0;
        for (char c : num)
        {
            int n = c - '0';
            cur = (cur * 10) + n;
            cur %= K;
        }

        num_mode[i] = cur;
    }

    // dp[mask][r] : mask 상태로 나머지 r인 경우의 수
    vector<vector<ll>> dp(1 << N, vector<ll>(K));
    dp[0][0] = 1;

    int mask_f = (1 << N) - 1;

    for (int mask = 0; mask <= mask_f; mask++)
    {
        for (int r = 0; r < K; r++)
            if (dp[mask][r])
                for (int p = 0; p < N; p++)
                {
                    if (mask >> p & 1)
                        continue;

                    int nr = (r * digit_mode[arr[p].size()] + num_mode[p]) % K;
                    dp[mask | (1 << p)][nr] += dp[mask][r];
                }
    }

    ll denom = 1;
    for (int i = 2; i <= N; i++)
        denom *= i;

    ll g = gcd(denom, dp[mask_f][0]);
    cout << dp[mask_f][0] / g << '/' << denom / g;

    // inputFileStream.close();
    return 0;
}
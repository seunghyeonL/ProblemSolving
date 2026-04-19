#include <bits/stdc++.h>
using namespace std;
const int NMX = 100;
int N;
int W[NMX + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    bool isOdd = N % 2;

    for (int i = 1; i <= N; ++i)
        cin >> W[i];

    int total = accumulate(W + 1, W + N + 1, 0);
    int need = isOdd ? N / 2 + 1 : N / 2;
    int S = total / 2;

    vector<vector<bool>> dp(need + 1, vector<bool>(S + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= N; ++i)
    {
        int w = W[i];
        for (int c = need; c >= 1; --c)
        {
            for (int s = S; s >= w; --s)
            {
                if (dp[c - 1][s - w])
                    dp[c][s] = true;
            }
        }
    }

    int best = 0;
    for (int s = 0; s <= S; ++s)
    {
        if (dp[need][s])
            best = s;

        if (isOdd && dp[need - 1][s])
            best = s;
    }

    int a = min(best, total - best);
    int b = total - a;
    cout << a << ' ' << b << '\n';
    return 0;
}

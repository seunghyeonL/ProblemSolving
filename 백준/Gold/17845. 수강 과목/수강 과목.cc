#include <bits/stdc++.h>
using namespace std;
const int NMX = 10000;
int N, K;
int I[NMX];
int T[NMX];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> I[i];
        cin >> T[i];
    }

    // dp[t] : t시간에 얻는 최대 중요도
    vector<int> dp(N + 1);

    for (int i = 0; i < K; i++)
    {
        int imp = I[i];
        int need = T[i];

        for (int t = N; t >= 1; t--)
        {
            if (t >= need)
            {
                dp[t] = max(dp[t], dp[t - need] + imp);
            }
        }
    }

    cout << dp[N] << '\n';

    // inputFileStream.close();
    return 0;
}
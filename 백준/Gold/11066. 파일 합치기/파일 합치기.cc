#include <bits/stdc++.h>
using namespace std;

const int KMX = 500;
int K;
int arr[KMX];
int dp[KMX][KMX]; // dp[i][j] : arr[i, j]를 합치는 최소 비용

void reset()
{
    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            dp[i][j] = 0;
}

void solve()
{
    cin >> K;

    reset();

    for (int i = 0; i < K; i++)
        cin >> arr[i];

    for (int len = 2; len <= K; len++)
    {
        for (int i = 0; i <= K - len; i++)
        {
            int j = i + len - 1;
            int sum = accumulate(arr + i, arr + j + 1, 0);
            int mn = 1e9;

            for (int k = i; k < j; k++)
            {
                mn = min(mn, dp[i][k] + dp[k + 1][j]);
            }

            dp[i][j] = mn + sum;
        }
    }

    cout << dp[0][K - 1] << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
     */

    int T;
    cin >> T;

    while (T-- > 0)
        solve();

    // inputFileStream.close();
    return 0;
}
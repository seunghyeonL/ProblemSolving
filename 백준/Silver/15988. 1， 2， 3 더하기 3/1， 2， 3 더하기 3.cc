#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000009;
const int NMX = 1000000;
int T;
int N;
long long dp[NMX + 1];
/*
    1

    1 1
    2

    1 1 1
    2 1
    1 2
    3

    1 1 1 1
    2 1 1
    1 2 1
    3 1
    1 1 2
    2 2
    1 3
*/

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");
    cin >> T;
    dp[0] = 1;

    for (int i = 1; i <= NMX; i++)
    {
        if (i >= 1)
            dp[i] += dp[i - 1];
        if (i >= 2)
            dp[i] += dp[i - 2];
        if (i >= 3)
            dp[i] += dp[i - 3];

        dp[i] %= MOD;
    }

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cout << dp[N] << '\n';
    }

    // inputFileStream.close();
    return 0;
}
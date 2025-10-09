#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000;
int N;
long long dp[NMX + 1];

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

    cin >> N;
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        dp[i] += dp[i - 1];
        dp[i] %= 10007;
        dp[i] += dp[i - 2] * 2;
        dp[i] %= 10007;
    }

    cout << dp[N] << '\n';

    // inputFileStream.close();
    return 0;
}
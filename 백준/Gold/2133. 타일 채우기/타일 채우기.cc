#include <bits/stdc++.h>
using namespace std;

const int NMX = 30;
int N;
int dp[NMX + 1];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     */

    // ifstream inputFileStream("input.txt");

    cin >> N;

    // dp[i] = dp[i - 2] * 3 + dp[i - 4] * 2 + dp[i - 6] * 2 + ...

    dp[0] = 1;
    dp[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        dp[i] += 3 * dp[i - 2];

        for (int j = 4; j <= i; j += 2)
        {
            dp[i] += 2 * dp[i - j];
        }
    }

    cout << dp[N];

    // inputFileStream.close();
    return 0;
}
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
        bottom up
        dp[i] = min(dp[i - 1] + 1, i가 2의 배수면 dp[i / 2] + 1, i가 3의 배수면 dp[i / 3] + 1)
    */

    int N;
    cin >> N;

    vector<int> dp(N + 1, 0);
    dp[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        int res = dp[i - 1] + 1;

        if (i % 2 == 0)
        {
            res = min(res, dp[i / 2] + 1);
        }

        if (i % 3 == 0)
        {
            res = min(res, dp[i / 3] + 1);
        }

        dp[i] = res;
    }

    cout << dp[N] << '\n';

    // inputFileStream.close();
    return 0;
}

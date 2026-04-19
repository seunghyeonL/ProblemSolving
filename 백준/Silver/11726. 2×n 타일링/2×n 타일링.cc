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
        세로로 놓으면 한칸 차지
        가로로 놓으면 두칸 차지

        +1, +2 해서 2n을 만드는 경우의 수

        1 1 1 1
        2   1 1
        1 2   1
        1 1   2
        2   2
    */

    const int MOD = 10007;
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    // dp[i] = dp[i - 1] + dp[i - 2]

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= MOD;
    }

    cout << dp[n] << '\n';

    // inputFileStream.close();
    return 0;
}

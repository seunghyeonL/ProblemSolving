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
        dp, 경로복원
    */

    int N;
    cin >> N;

    // dp[i] : i를 만드는 연산의 최소 횟수
    vector<int> dp(N + 1);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    // pre[i] : 이전 경로
    vector<int> pre(N + 1);
    pre[1] = 1;
    pre[2] = 1;
    pre[3] = 1;

    // dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1; 나눠질때만, dp[i / 3] + 1; 나눠질때만)

    for (int i = 4; i <= N; i++)
    {
        int mn = dp[i - 1];
        pre[i] = i - 1;

        if (i % 2 == 0 && dp[i / 2] < mn)
        {
            mn = min(mn, dp[i / 2]);
            pre[i] = i / 2;
        }

        if (i % 3 == 0 && dp[i / 3] < mn)
        {
            mn = min(mn, dp[i / 3]);
            pre[i] = i / 3;
        }

        dp[i] = mn + 1;
    }

    cout << dp[N] << '\n';

    int p = N;
    while (p > 1)
    {
        cout << p << ' ';
        p = pre[p];
    }
    cout << 1 << '\n';

    // inputFileStream.close();
    return 0;
}
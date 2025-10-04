#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin >> N;

    // fibo(N)의 fibo(0) 호출 횟수, fibo(1) 호출 횟수
    vector<pair<int, int>> dp(N + 1);

    dp[0] = {1, 0};
    dp[1] = {0, 1};

    for (int i = 2; i <= N; i++)
    {
        dp[i] = {dp[i - 2].first + dp[i - 1].first,
                 dp[i - 2].second + dp[i - 1].second};
    }

    cout << dp[N].first << ' ' << dp[N].second << '\n';
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
    for (int i = 0; i < T; i++)
    {
        solve();
    }

    // inputFileStream.close();
    return 0;
}

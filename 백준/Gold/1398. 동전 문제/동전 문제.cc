#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

void solve()
{
    ll P;
    cin >> P;

    ll ans = 0;
    // dp[i] : {1, 10, 25} 로 i원을 내는 최소 동전 개수
    vector<int> dp(101, 100);
    dp[0] = 0;

    while (P > 0)
    {
        int cp = P % 100;

        fill(dp.begin() + 1, dp.begin() + cp + 1, 100);

        for (int coin : {1, 10, 25})
            for (int i = coin; i <= cp; i++)
                dp[i] = min(dp[i], dp[i - coin] + 1);

        ans += dp[cp];

        P = P / 100;
    }

    cout << ans << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    // 100단위로 끊어서 1, 10, 25로 내는 최소 동전수 찾아서 더하기

    int T;
    cin >> T;

    while (--T >= 0)
        solve();

    // inputFileStream.close();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000003;
const int NMX = 1000;
int N, K;

// j : idx
// k : 선택한 색상 수
// i : j번째 색을 골랐는지 여부
// dp[i][k][j] : i, k상태로 1 ~ j번째 색 범위에서 고르는 경우의 수
int dp[2][NMX + 1][NMX + 1];

void reset_dp()
{
    for (int i = 0; i < 2; i++)
    {
        for (int k = 0; k <= K; k++)
        {
            for (int j = 1; j <= N; j++)
            {
                dp[i][k][j] = 0;
            }
        }
    }
}

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

    cin >> N >> K;

    /*
        dp[0][k][i] = dp[0][k][i - 1] + dp[1][k][i - 1];
        dp[1][k][i] = dp[0][k - 1][i - 1];
    */

    int ans = 0;
    // 첫번째 색을 고르는 경우
    reset_dp();
    dp[1][1][1] = 1;

    for (int i = 2; i <= N; i++)
    {
        for (int k = 0; k <= min(i, K); k++)
        {
            if (k < i)
                dp[0][k][i] = (dp[0][k][i - 1] + dp[1][k][i - 1]) % MOD;
            if (k >= 1)
                dp[1][k][i] = dp[0][k - 1][i - 1];
        }
    }

    ans += dp[0][K][N];
    ans %= MOD;

    // 첫번째 색을 고르지 않는 경우
    reset_dp();
    dp[0][0][1] = 1;

    for (int i = 2; i <= N; i++)
    {
        for (int k = 0; k <= min(i, K); k++)
        {
            if (k < i)
                dp[0][k][i] = (dp[0][k][i - 1] + dp[1][k][i - 1]) % MOD;
            if (k >= 1)
                dp[1][k][i] = dp[0][k - 1][i - 1];
        }
    }

    // 첫 번째 색을 고르지 않았으니 마지막 색을 골라도 된다.
    // (물론 고르지 않아도 된다.)
    ans += dp[0][K][N];
    ans %= MOD;
    ans += dp[1][K][N];
    ans %= MOD;

    cout << ans;

    // inputFileStream.close();
    return 0;
}
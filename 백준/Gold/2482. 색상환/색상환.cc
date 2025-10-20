#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000003;
const int NMX = 1000;
int N, K;

// dp[i][k] : i개의 수에서 인접하지 않고 j개를 고르는 경우의 수
int dp[NMX + 1][NMX + 1];

// dp[i][k] = dp[i - 1][k] + dp[i - 2][k - 1];

void init_dp()
{
    for (int i = 0; i <= N; i++)
    {
        dp[i][1] = i;
        dp[i][0] = 1;
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

    init_dp();
    for (int i = 2; i <= N; i++)
    {
        for (int k = 2; k <= min(K, (i + 1) / 2); k++)
        {
            dp[i][k] = (dp[i - 1][k] + dp[i - 2][k - 1]) % MOD;
        }
    }

    // 첫 요소를 선택하는 경우 + 선택하지 않는 경우
    cout << (dp[N - 3][K - 1] + dp[N - 1][K]) % MOD;

    // inputFileStream.close();
    return 0;
}
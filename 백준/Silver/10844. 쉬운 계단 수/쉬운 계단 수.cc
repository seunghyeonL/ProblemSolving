#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000000;
const int NMX = 100;
int N;
int dp[10][NMX + 1]; // dp[n][l] : 길이가 l인 n으로 끝나는 계단수 갯수

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

    dp[0][1] = 0;
    for (int i = 1; i <= 9; i++)
    {
        dp[i][1] = 1;
    }

    for (int l = 2; l <= N; l++)
    {
        dp[0][l] = dp[1][l - 1];
        dp[9][l] = dp[8][l - 1];

        for (int n = 1; n <= 8; n++)
        {
            dp[n][l] = (dp[n - 1][l - 1] + dp[n + 1][l - 1]) % MOD;
        }
    }

    int answer = 0;
    for (int n = 0; n <= 9; n++)
    {
        answer += dp[n][N];
        answer %= MOD;
    }

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}
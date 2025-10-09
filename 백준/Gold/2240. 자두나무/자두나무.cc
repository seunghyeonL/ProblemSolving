#include <bits/stdc++.h>
using namespace std;

const int TMX = 1000;
const int WMX = 30;

int T, W;
int dp[WMX + 1][TMX + 1]; // dp[i][j] : i번 움직인 상태, j초에 얻을 수 있는 최대
                          // 자두 양; i번 움직였을때 자두 위치는 i % 2 + 1
// dp[i][j] = max(dp[i][j - 1],  dp[i - 1][j - 1]) + 이 타이밍에 2 % i + 1에서
// 자두가 떨어지는가?;

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

    cin >> T >> W;
    for (int t = 1; t <= T; t++)
    {
        int p;
        cin >> p;
        dp[0][t] = dp[0][t - 1] + (p == 1);
        for (int w = 1; w <= min(t, W); w++)
        {
            dp[w][t] = max(dp[w - 1][t - 1], dp[w][t - 1]) + (p == w % 2 + 1);
        }
    }

    int answer = 0;
    for (int w = 0; w <= W; w++)
    {
        answer = max(answer, dp[w][T]);
    }
    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}
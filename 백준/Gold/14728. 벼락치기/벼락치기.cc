#include <bits/stdc++.h>
using namespace std;
const int NMX = 100;
const int TMX = 10000;
int N, T;
int study[NMX + 1];
int score[NMX + 1];
// dp[i][j] : i번째 과목까지 j시간으로 공부할 때 얻을 수 있는 최대 점수
int dp[NMX + 1][TMX + 1];

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

    cin >> N >> T;

    for (int i = 1; i <= N; i++)
    {
        cin >> study[i];
        cin >> score[i];
    }

    // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - study[i]] + score[i])

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= T; j++)
        {
            if (j < study[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] =
                    max(dp[i - 1][j], dp[i - 1][j - study[i]] + score[i]);
        }
    }

    cout << dp[N][T] << '\n';

    // inputFileStream.close();
    return 0;
}
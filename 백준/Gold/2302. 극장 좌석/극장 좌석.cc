#include <bits/stdc++.h>
using namespace std;
const int NMX = 40;
int N, M;
vector<int> isFixed(NMX + 1);
int dp[2][NMX + 1];
// i : i -1 자리와 자리를 바꿨는지 여부
// dp[i][j] : i상태에서 [0, j] 경우의 수

/*
    dp[0][j] = dp[0][j - 1] + dp[1][j - 1];
    dp[1][j] = dp[0][j  -2] + dp[1][j - 2] = dp[0][j - 1];
*/

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

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;

        isFixed[x] = true;
    }

    dp[0][1] = 1;
    dp[1][1] = 0;

    for (int x = 2; x <= N; x++)
    {
        if (isFixed[x - 1] || isFixed[x])
        {
            dp[1][x] = 0;
        }
        else
        {
            dp[1][x] = dp[0][x - 1];
        }

        dp[0][x] = dp[0][x - 1] + dp[1][x - 1];
    }

    cout << dp[0][N] + dp[1][N] << '\n';

    // inputFileStream.close();
    return 0;
}
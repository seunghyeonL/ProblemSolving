#include <bits/stdc++.h>
using namespace std;
const int NMX = 10000;
int N;
vector<int> arr(NMX + 1);
int dp[3][NMX + 1];
// i : j번째 잔까지 연속해서 먹은 잔 개수
// dp[i][j] : j번째 잔까지 먹은 포도주 양

/*
    dp[0][i] = dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1];
    dp[1][i] = dp[0][i - 1] + arr[i];
    dp[2][i] = dp[1][i - 1] + arr[i];
*/

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    dp[0][1] = 0;
    dp[1][1] = arr[1];
    dp[2][1] = 0;

    for (int i = 2; i <= N; i++)
    {
        dp[0][i] = max({dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]});
        dp[1][i] = dp[0][i - 1] + arr[i];
        dp[2][i] = dp[1][i - 1] + arr[i];
    }

    cout << max({dp[0][N], dp[1][N], dp[2][N]}) << '\n';

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int NMX = 500;
int N;
pair<int, int> arr[NMX];
// dp[i][j] : arr[i, j] 범위 행렬을 곱할때 최소 연산량
long long dp[NMX][NMX];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = INF;

    for (int i = 0; i < N; i++)
        dp[i][i] = 0;

    for (int i = 0; i < N; i++)
    {
        int r, c;
        cin >> r >> c;

        arr[i] = {r, c};
    }

    for (int len = 2; len <= N; len++)
    {
        for (int i = 0; i <= N - len; i++)
        {
            int j = i + len - 1;

            for (int k = i; k < j; k++)
            {
                int a, b, c;
                a = arr[i].first;
                b = arr[k].second;
                c = arr[j].second;

                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a * b * c);
            }
        }
    }

    cout << dp[0][N - 1] << '\n';

    // inputFileStream.close();
    return 0;
}
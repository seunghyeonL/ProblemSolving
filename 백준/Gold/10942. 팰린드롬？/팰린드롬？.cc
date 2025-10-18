#include <bits/stdc++.h>
using namespace std;

const int NMX = 2000;
int N, M;

int arr[NMX + 1];
bool dp[NMX + 1][NMX + 1]; // dp[i][j] : arr[i, j] 가 팰린드롭인지 여부

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

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    // len == 1
    for (int i = 1; i <= N; i++)
        dp[i][i] = true;

    // len == 2
    for (int i = 1; i <= N - 1; i++)
        dp[i][i + 1] = arr[i] == arr[i + 1];

    // len >= 3
    // dp[i][j] = dp[i + 1][j - 1] && arr[i] == arr[j]

    for (int len = 3; len <= N; len++)
    {
        for (int i = 1; i <= N - len + 1; i++)
        {
            dp[i][i + len - 1] =
                dp[i + 1][i + len - 2] && arr[i] == arr[i + len - 1];
        }
    }

    cin >> M;
    while (M-- > 0)
    {
        int i, j;
        cin >> i >> j;

        cout << dp[i][j] << '\n';
    }

    // inputFileStream.close();
    return 0;
}
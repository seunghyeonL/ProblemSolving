#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
const int INF = NMX + 1;
int N;
int dp[NMX + 1]; // dp[i] : i의 제곱수 항 최소 개수

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
    fill(dp, dp + N + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[N];

    // inputFileStream.close();
    return 0;
}
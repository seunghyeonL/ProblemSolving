#include <bits/stdc++.h>
using namespace std;
const int NMX = 15;
int N;
int T[NMX + 1];
int P[NMX + 1];
int dp[NMX + 2]; // dp[i] : i일에 벌수 있는 최대 금액

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

    for (int i = 1; i <= N; i++)
    {
        cin >> T[i];
        cin >> P[i];
    }

    for (int i = 1; i <= N; i++)
    {
        int ed = i + T[i];
        if (ed <= N + 1)
        {
            for (int j = ed; j <= N + 1; j++)
                dp[j] = max(dp[j], dp[i] + P[i]);
        }
    }

    cout << dp[N + 1] << '\n';

    // inputFileStream.close();
    return 0;
}
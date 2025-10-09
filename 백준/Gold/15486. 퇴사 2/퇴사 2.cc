#include <bits/stdc++.h>
using namespace std;
const int NMX = 1500000;
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
        // 전날 상담을 스킵한 경우
        dp[i] = max(dp[i], dp[i - 1]);
        // 오늘 상담하고 다음 상담할 수 있는 첫 날
        int ed = i + T[i];

        if (ed <= N + 1)
        {
            dp[ed] = max(dp[ed], dp[i] + P[i]);
        }
    }

    cout << max(dp[N], dp[N + 1]) << '\n';

    // inputFileStream.close();
    return 0;
}
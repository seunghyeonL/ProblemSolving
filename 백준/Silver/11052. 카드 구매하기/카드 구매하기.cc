#include <bits/stdc++.h>
using namespace std;
const int NMX = 1000;
int N;
int P[NMX + 1];
int dp[NMX + 1]; // dp[i] : 카드 i개를 사는 최대 금액

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
        cin >> P[i];

    dp[0] = 0;

    for (int i = 1; i <= N; i++) // 카드백 번호
    {
        for (int n = i; n <= N; n++) // 카드 개수
        {
            dp[n] = max(dp[n], dp[n - i] + P[i]);
        }
    }

    cout << dp[N] << '\n';

    // inputFileStream.close();
    return 0;
}
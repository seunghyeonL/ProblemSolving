#include <bits/stdc++.h>
using namespace std;
const int MMX = 20;
int N, M;
int day[MMX];
int page[MMX];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> day[i];
        cin >> page[i];
    }

    // dp[i] : i일로 읽을 수 있는 최대 페이지 수
    vector<int> dp(N + 1);

    for (int i = 0; i < M; i++)
    {
        int d = day[i];
        int p = page[i];

        for (int t = N; t >= 1; t--)
        {
            if (t >= d)
                dp[t] = max(dp[t], dp[t - d] + p);
        }
    }

    cout << dp[N] << '\n';

    // inputFileStream.close();
    return 0;
}
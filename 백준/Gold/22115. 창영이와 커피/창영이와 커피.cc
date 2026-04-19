#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int N, K;
    cin >> N >> K;

    vector<int> C(N);
    for (int i = 0; i < N; i++)
        cin >> C[i];

    // dp[n][k] : n개의 커피로 k 카페인을 얻을 수 있는지 여부
    vector<vector<bool>> dp(N + 1, vector<bool>(K + 1));
    dp[0][0] = true;

    for (int i = 0; i < N; i++)
    {
        int c = C[i];
        for (int n = N; n >= 1; n--)
            for (int k = K; k >= c; k--)
            {
                if (dp[n - 1][k - c])
                    dp[n][k] = true;
            }
    }

    int answer = -1;
    for (int n = 0; n <= N; n++)
    {
        if (dp[n][K])
        {
            answer = n;
            break;
        }
    }

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}
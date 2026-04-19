#include <bits/stdc++.h>
using namespace std;

const int INF = 200000;
const int NMX = 20;
int N;
int D[NMX + 1][NMX + 1];

// dp[mask(k)] : 1 ~ k번 사람에게 k개의 일을 mask로 배정할때 최소 비용
int dp[1 << NMX];

int get_cnt_on(int mask)
{
    int ret = 0;

    for (int p = 0; p < N; p++)
    {
        if (mask >> p & 1)
            ret++;
    }

    return ret;
}

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
        for (int j = 1; j <= N; j++)
            cin >> D[i][j];

    // dp[0] == 0;
    fill(dp + 1, dp + (1 << N), INF);

    for (int mask = 0; mask < 1 << N; mask++)
    {
        // 켜진 비트 갯수 == 배정된 사람 수
        // -> 이번에 배정할 사람은 n + 1 번째 사람
        int n = get_cnt_on(mask);

        if (n == N)
            continue;

        for (int p = 0; p < N; p++) // p : 배정할 일 idx -> p + 1 번째 일
        {
            if (mask >> p & 1)
                continue;
            int nmask = mask | 1 << p;

            dp[nmask] = min(dp[nmask], dp[mask] + D[n + 1][p + 1]);
        }
    }

    cout << dp[(1 << N) - 1];

    // inputFileStream.close();
    return 0;
}
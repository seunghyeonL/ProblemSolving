#include <bits/stdc++.h>
using namespace std;
const int NMX = 100;
int N, M;
int mem[NMX];
int cost[NMX];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> mem[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> cost[i];
    }

    int mxMem = accumulate(mem, mem + N, 0);
    int mxCost = accumulate(cost, cost + N, 0);

    // dp[i] : i바이트를 확보할 때 최소 비용
    vector<int> dp(mxMem + 1, mxCost);
    dp[0] = 0;

    for (int i = 0; i < N; i++)
    {
        int m = mem[i];
        int c = cost[i];

        for (int b = mxMem; b >= 1; b--)
        {
            if (b >= m)
                dp[b] = min(dp[b], dp[b - m] + c);
        }
    }

    // Printc<vector<int>>()(dp);

    int answer = *min_element(dp.begin() + M, dp.end());
    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}
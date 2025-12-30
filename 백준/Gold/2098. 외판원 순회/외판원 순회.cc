#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int NMX = 16;
int N;
int adj[NMX + 1][NMX + 1];
// dp[현재까지 방문 노드 mask, 현재 노드] = 최소 비용
int dp[1 << (NMX + 1)][NMX + 1];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    // 현재까지 방문한 노드들, 현재 노드 dp

    cin >> N;
    for (int u = 1; u <= N; u++)
        for (int v = 1; v <= N; v++)
            cin >> adj[u][v];

    fill(&dp[0][0], &dp[0][0] + (1 << (NMX + 1)) * (NMX + 1), INF);

    // 시작점을 1로
    int sv = 1;
    dp[1 << sv][sv] = 0;

    int f_mask = (1 << (N + 1)) - 2;

    for (int mask = 0; mask <= f_mask; mask++)
    {
        if (!(mask >> sv & 1))
            continue;

        for (int cv = 1; cv <= N; cv++)
        {
            if (!(mask >> cv & 1))
                continue;

            for (int nv = 1; nv <= N; nv++)
            {
                if (mask >> nv & 1)
                    continue;

                if (!adj[cv][nv])
                    continue;

                int n_mask = mask | 1 << nv;
                dp[n_mask][nv] = min(dp[n_mask][nv], dp[mask][cv] + adj[cv][nv]);
            }
        }
    }

    int ans = INF;
    for (int u = 1; u <= N; u++)
    {
        if (dp[f_mask][u] == INF)
            continue;

        if (!adj[u][sv])
            continue;

        ans = min(ans, dp[f_mask][u] + adj[u][sv]);
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}

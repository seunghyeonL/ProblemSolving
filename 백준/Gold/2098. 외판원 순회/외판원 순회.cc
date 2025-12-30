#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int NMX = 16;
int N;
int adj[NMX + 1][NMX + 1];
// dp[현재까지 방문 노드 mask, 현재 노드] = 최소 비용
int dp[1 << (NMX + 1)][NMX + 1];

int dijkstra(int sv)
{
    fill(&dp[0][0], &dp[0][0] + (1 << (NMX + 1)) * (NMX + 1), INF);

    // 현재까지 비용, 현재 마스크, 현재 노드
    using T = tuple<int, int, int>;
    priority_queue<T, vector<T>, greater<T>> pq;

    pq.emplace(0, 1 << sv, sv);
    dp[1 << sv][sv] = 0;

    int ret = INF;

    while (!pq.empty())
    {
        auto [cost, mask, cv] = pq.top();
        pq.pop();

        if (dp[mask][cv] < cost)
            continue;

        if (mask == (1 << (N + 1)) - 2)
        {
            if (adj[cv][sv])
                ret = min(ret, cost + adj[cv][sv]);

            continue;
        }

        for (int nv = 1; nv <= N; nv++)
        {
            if (!adj[cv][nv])
                continue;

            if (mask >> nv & 1)
                continue;

            int n_mask = mask | 1 << nv;
            if (dp[n_mask][nv] > dp[mask][cv] + adj[cv][nv])
            {
                dp[n_mask][nv] = dp[mask][cv] + adj[cv][nv];
                pq.emplace(dp[n_mask][nv], n_mask, nv);
            }
        }
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

    // 현재까지 방문한 노드들, 현재 노드 dp

    cin >> N;
    for (int u = 1; u <= N; u++)
        for (int v = 1; v <= N; v++)
            cin >> adj[u][v];

    int ans = dijkstra(1);

    cout << ans;

    // inputFileStream.close();
    return 0;
}

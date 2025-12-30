#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int NMX = 16;
int N;
int adj[NMX + 1][NMX + 1];

int memo[1 << (NMX + 1)][NMX + 1];
int sv, f_mask;

// mask, cv 상태에서 다 채우고 sv로 돌아가는 최소 비용
int dfs(int mask, int cv)
{
    if (memo[mask][cv] != -1)
        return memo[mask][cv];

    if (mask == f_mask)
    {
        if (adj[cv][sv])
            return memo[mask][cv] = adj[cv][sv];
        else
            return memo[mask][cv] = INF;
    }

    int ret = INF;

    for (int nv = 1; nv <= N; nv++)
    {
        if (mask >> nv & 1)
            continue;

        if (!adj[cv][nv])
            continue;

        ret = min(ret, adj[cv][nv] + dfs(mask | (1 << nv), nv));
    }

    return memo[mask][cv] = ret;
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

    memset(memo, -1, sizeof(memo));
    f_mask = (1 << (N + 1)) - 2;
    sv = 1;

    cout << dfs(1 << sv, sv);

    // inputFileStream.close();
    return 0;
}

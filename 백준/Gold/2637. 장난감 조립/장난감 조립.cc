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

    constexpr int NMX = 100;
    int N, M;
    cin >> N >> M;

    // 부품 -> {개수, 상위부품}
    vector<pair<int, int>> adj[NMX + 1]{};
    vector<int> indeg(N + 1);

    for (int i = 0; i < M; i++)
    {
        int x, y, k;
        cin >> x >> y >> k;

        adj[y].emplace_back(k, x);
        indeg[x]++;
    }

    // dp[v][u] : v를 만들때 필요한 u 개수(최하위 부품만)
    int dp[NMX + 1][NMX + 1];

    queue<int> q;

    for (int u = 1; u <= N; u++)
    {
        if (indeg[u] == 0)
        {
            q.push(u);
            dp[u][u] = 1;
        }
    }

    while (!q.empty())
    {
        int cv = q.front();
        q.pop();

        for (auto [w, nv] : adj[cv])
        {
            for (int u = 1; u <= N; u++)
                dp[nv][u] += dp[cv][u] * w;

            if (--indeg[nv] == 0)
                q.push(nv);
        }
    }

    for (int u = 1; u <= N; u++)
    {
        if (dp[N][u])
            cout << u << ' ' << dp[N][u] << '\n';
    }

    // inputFileStream.close();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int NMX = 100;
int N, M;
int dist[NMX + 1][NMX + 1];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*

    */

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dist[i][j] = INF;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        dist[u][v] = 1;
        dist[v][u] = 1;
    }

    for (int i = 1; i <= N; i++)
        dist[i][i] = 0;

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int mnkb = INF;
    int res{};

    for (int i = 1; i <= N; i++)
    {
        int kbi = accumulate(dist[i] + 1, dist[i] + N + 1, 0);
        if (mnkb > kbi)
        {
            mnkb = kbi;
            res = i;
        }
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int NMX = 100;
int N, M, R;
int items[NMX + 1];
int dist[NMX + 1][NMX + 1];

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

    cin >> N >> M >> R;
    for (int u = 1; u <= N; u++)
        cin >> items[u];

    for (int u = 1; u <= N; u++)
        for (int v = 1; v <= N; v++)
            dist[u][v] = INF;

    for (int i = 0; i < R; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    for (int u = 1; u <= N; u++)
        dist[u][u] = 0;

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int mx = 0;
    for (int u = 1; u <= N; u++)
    {
        int sum = 0;
        for (int v = 1; v <= N; v++)
        {
            if (dist[u][v] <= M)
            {
                sum += items[v];
            }

            mx = max(mx, sum);
        }
    }

    cout << mx;
    // inputFileStream.close();
    return 0;
}
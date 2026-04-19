#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int VMX = 400;
int V, E;
int dist[VMX + 1][VMX + 1];

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

    cin >> V >> E;

    for (int u = 1; u <= V; u++)
        for (int v = 1; v <= V; v++)
            dist[u][v] = INF;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        dist[u][v] = w;
    }

    for (int u = 1; u <= V; u++)
        dist[u][u] = 0;

    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int mn = INF;
    for (int u = 1; u <= V; u++)
        for (int v = 1; v <= V; v++)
        {
            if (u != v)
                mn = min(mn, dist[u][v] + dist[v][u]);
        }

    cout << (mn == INF ? -1 : mn);

    // inputFileStream.close();
    return 0;
}
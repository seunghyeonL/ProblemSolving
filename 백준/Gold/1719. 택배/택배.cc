#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int NMX = 200;
int N, M;
int dist[NMX + 1][NMX + 1];
int nxt[NMX + 1][NMX + 1];

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

    cin >> N >> M;

    for (int u = 1; u <= N; u++)
        for (int v = 1; v <= N; v++)
            if (u != v)
                dist[u][v] = INF;

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        dist[u][v] = w;
        dist[v][u] = w;

        nxt[u][v] = v;
        nxt[v][u] = u;
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }

    for (int u = 1; u <= N; u++)
    {
        for (int v = 1; v <= N; v++)
        {
            if (nxt[u][v])
                cout << nxt[u][v] << ' ';
            else
                cout << '-' << ' ';
        }
        cout << '\n';
    }

    // inputFileStream.close();
    return 0;
}
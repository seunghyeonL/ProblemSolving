#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 1;
const int NMX = 100;
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

    /*
     */

    // ifstream inputFileStream("input.txt");

    cin >> N >> M;
    for (int u = 1; u <= N; u++)
        for (int v = 1; v <= N; v++)
            dist[u][v] = INF;

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        dist[u][v] = min(dist[u][v], w);
        nxt[u][v] = v;
    }

    for (int u = 1; u <= N; u++)
    {
        dist[u][u] = 0;
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

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << (dist[i][j] == INF ? 0 : dist[i][j]) << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int cnt = 1;
            int u = i;
            int v = j;

            if (nxt[u][v] == 0)
            {
                cout << 0 << '\n';
                continue;
            }

            vector<int> history;
            history.push_back(u);
            while (u != v)
            {
                history.push_back(nxt[u][v]);
                u = nxt[u][v];
                cnt++;
            }

            cout << cnt << ' ';
            for (int el : history)
            {
                cout << el << ' ';
            }
            cout << '\n';
        }
    }

    // inputFileStream.close();
    return 0;
}
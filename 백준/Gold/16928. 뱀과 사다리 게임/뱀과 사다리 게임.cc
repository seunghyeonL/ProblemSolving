#include <bits/stdc++.h>
using namespace std;

const int MX = 100;
int N, M;
int adj[MX + 1];
int dist[MX + 1];

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
        int u, v;
        cin >> u >> v;
        adj[u] = v;
    }

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u] = v;
    }

    fill(dist, dist + MX + 1, -1);

    queue<int> q;

    dist[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        int cv = q.front();
        q.pop();

        if (cv == 100)
            break;

        for (int dx : {1, 2, 3, 4, 5, 6})
        {
            int nv = cv + dx;
            if (nv > 100)
                continue;

            if (adj[nv] > 0)
                nv = adj[nv];

            if (dist[nv] == -1)
            {
                dist[nv] = dist[cv] + 1;
                q.push(nv);
            }
        }
    }

    cout << dist[100];

    // inputFileStream.close();
    return 0;
}
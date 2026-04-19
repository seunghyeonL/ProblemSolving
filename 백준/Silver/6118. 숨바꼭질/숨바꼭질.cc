#include <bits/stdc++.h>
using namespace std;
const int NMX = 20000;
int N, M;
vector<int> adj[NMX + 1];
int dist[NMX + 1];

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
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(dist, dist + N + 1, -1);

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    int curDist = 0;
    int frontNode = 1;
    int cnt = 1;

    while (!q.empty())
    {
        int cv = q.front();
        q.pop();

        if (dist[cv] > curDist)
        {
            frontNode = cv;
            curDist = dist[cv];
            cnt = 1;
        }
        else
        {
            frontNode = min(frontNode, cv);
            cnt++;
        }

        for (int nv : adj[cv])
        {
            if (dist[nv] == -1)
            {
                q.push(nv);
                dist[nv] = dist[cv] + 1;
            }
        }
    }

    cout << frontNode << ' ' << curDist << ' ' << cnt << '\n';

    // inputFileStream.close();
    return 0;
}
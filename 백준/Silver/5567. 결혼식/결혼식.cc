#include <bits/stdc++.h>
using namespace std;
int N, M;
int dist[501];
vector<int> adj[501];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(dist, dist + 501, -1);

    int answer = 0;

    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        int cv = q.front();
        q.pop();

        if (dist[cv] > 2)
            break;

        if (cv > 1)
        {
            answer++;
        }

        for (int nv : adj[cv])
        {
            if (dist[nv] == -1)
            {
                dist[nv] = dist[cv] + 1;
                q.push(nv);
            }
        }
    }

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}
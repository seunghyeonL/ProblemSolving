#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
int N, M, R;
vector<int> adj[NMX + 1];
int vis[NMX + 1];
int order;

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

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(adj[i].begin(), adj[i].end(), greater<int>());
    }

    queue<int> q;

    vis[R] = ++order;
    q.push(R);

    while (!q.empty())
    {
        int cv = q.front();
        q.pop();

        for (int nv : adj[cv])
        {
            if (!vis[nv])
            {
                vis[nv] = ++order;
                q.push(nv);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << vis[i] << '\n';
    }

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int VMX = 20000;
int V, E;
vector<int> adj[VMX + 1];
int vis[VMX + 1];

void reset()
{
    for (int i = 1; i <= V; i++)
    {
        adj[i].clear();
        vis[i] = 0;
    }
}

void has_odd_cycle(int cv, bool &res)
{
    for (int nv : adj[cv])
    {
        if (res)
            break;

        if (vis[nv])
        {
            if ((vis[cv] - vis[nv]) % 2 == 0)
            {
                res = true;
                break;
            }

            continue;
        }

        vis[nv] = vis[cv] + 1;
        has_odd_cycle(nv, res);
    }
}

void solve()
{
    cin >> V >> E;
    reset();

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int v = 1; v <= V; v++)
    {
        if (vis[v] == 0)
        {
            vis[v] = 1;
            bool res = false;
            has_odd_cycle(v, res);

            if (res)
            {
                cout << "NO" << '\n';
                return;
            }
        }
    }

    cout << "YES" << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int T;
    cin >> T;
    while (T-- > 0)
        solve();

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> adj[10001];
bool vis[10001];

void resetVis()
{
    fill(vis, vis + 10001, false);
}

int dfs(int cv)
{
    if (vis[cv])
        return 0;

    vis[cv] = true;

    int res = 1;

    for (int nv : adj[cv])
    {
        if (!vis[nv])
            res += dfs(nv);
    }

    return res;
}

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

        adj[v].push_back(u);
    }

    int mx = 0;
    vector<int> res;

    for (int i = 1; i <= N; i++)
    {
        resetVis();
        int n = dfs(i);
        if (n > mx)
        {
            mx = n;
            res.clear();
            res.push_back(i);
        }
        else if (n == mx)
        {
            res.push_back(i);
        }
    }

    for (int el : res)
    {
        cout << el << ' ';
    }
    cout << '\n';

    // inputFileStream.close();
    return 0;
}
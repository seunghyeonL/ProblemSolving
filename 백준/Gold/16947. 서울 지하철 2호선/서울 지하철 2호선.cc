#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> adj[3001];

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

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> distFromCycle(N + 1, -1);

    {
        vector<int> depth(N + 1, -1);
        vector<int> pre(N + 1, -1);

        bool found = false;
        function<void(int, int)> dfs = [&](int cv, int pv)
        {
            if (found)
                return;
            for (int nv : adj[cv])
            {
                if (nv == pv)
                    continue;

                if (depth[nv] == -1)
                {
                    depth[nv] = depth[cv] + 1;
                    pre[nv] = cv;
                    dfs(nv, cv);
                }
                else if (depth[nv] < depth[cv])
                {
                    int p = cv;
                    while (1)
                    {
                        distFromCycle[p] = 0;
                        if (p == nv)
                            break;
                        p = pre[p];
                    }
                    found = true;
                    return;
                }
            }
        };

        for (int v = 1; v <= N; v++)
        {
            if (found)
                break;

            if (depth[v] == -1)
            {
                depth[v] = 0;
                dfs(v, 0);
            }
        }
    }

    vector<bool> visited(N + 1);

    function<void(int)> dfs = [&](int cv)
    {
        visited[cv] = true;

        for (int nv : adj[cv])
        {
            if (!visited[nv])
            {
                if (distFromCycle[nv] == -1)
                {
                    distFromCycle[nv] = distFromCycle[cv] + 1;
                    dfs(nv);
                }
                else
                {
                    dfs(nv);
                }
            }
        }
    };

    int ci = find(distFromCycle.begin(), distFromCycle.end(), 0) -
             distFromCycle.begin();

    dfs(ci);

    for (int i = 1; i <= N; i++)
    {
        cout << distFromCycle[i] << ' ';
    }
    cout << '\n';

    // inputFileStream.close();
    return 0;
}

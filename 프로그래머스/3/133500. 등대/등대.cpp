#include <string>
#include <vector>
#include <functional>

using namespace std;

int solution(int n, vector<vector<int>> lighthouse)
{
    vector<vector<int>> adj(n + 1);
    for (auto l : lighthouse)
    {
        int u = l[0];
        int v = l[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> light(n + 1);

    function<void(int, int)> dfs = [&](int cv, int pv)
    {
        for (int nv : adj[cv])
        {
            if (nv == pv)
                continue;

            dfs(nv, cv);

            if (!light[nv] && !light[cv])
            {
                light[cv] = true;
            }
        }
    };

    dfs(1, 0);

    return count(light.begin(), light.end(), true);
}

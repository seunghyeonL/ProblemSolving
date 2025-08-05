#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
    using P = pair<int, int>; // 가중치, 노드

    int INF = 1e8 + 1;
    vector<int> answer{n + 2, INF};

    unordered_set<int> gateSet(gates.begin(), gates.end());
    unordered_set<int> summitSet(summits.begin(), summits.end());

    vector<int> uf(n + 1, -1);

    function<int(int)> findRoot = [&](int u)
    {
        if (uf[u] < 0)
            return u;
        return uf[u] = findRoot(uf[u]);
    };

    auto unionSet = [&](int u, int v)
    {
        int ru = findRoot(u);
        int rv = findRoot(v);

        if (ru == rv)
            return false;

        if (uf[ru] > uf[rv])
        {
            uf[ru] = rv;
        }
        else if (uf[ru] == uf[rv])
        {
            uf[ru] = rv;
            uf[rv]--;
        }
        else
        {
            uf[rv] = ru;
        }
        return true;
    };

    vector<vector<P>>
        adj(n + 1);

    sort(paths.begin(), paths.end(), [](auto a, auto b)
         { return a[2] < b[2]; });

    int cnt = 0;
    for (auto path : paths)
    {
        int u = path[0];
        int v = path[1];
        int w = path[2];

        if (unionSet(u, v))
        {
            cnt++;
            adj[u].emplace_back(w, v);
            adj[v].emplace_back(w, u);
            if (cnt == n - 1)
                break;
        }
    }

    int summit = -1;

    // Printc<vector<vector<P>>, Printc<vector<P>, Printp<P>>> printc;
    // printc(adj);

    // start, finish, cur -> intensity
    function<void(int, int, vector<bool> &)> dfs = [&](int cv, int aw, vector<bool> &visited)
    {
        if (aw > answer[1])
            return;

        if (gateSet.count(cv) && answer[1] > aw)
        {
            answer[0] = summit;
            answer[1] = aw;
            return;
        }

        if (summitSet.count(cv) && cv != summit)
        {
            return;
        }

        for (auto [nw, nv] : adj[cv])
        {
            // cout << cv << ' ' << nv << '\n';
            if (visited[nv])
                continue;
            visited[nv] = true;
            dfs(nv, max(aw, nw), visited);
            visited[nv] = false;
        }
    };

    sort(summits.begin(), summits.end());

    for (int s : summits)
    {
        summit = s;
        vector<bool> visited(n + 1);
        visited[summit] = true;

        dfs(summit, 0, visited);
    }

    return answer;
}


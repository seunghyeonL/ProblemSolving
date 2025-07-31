#include <string>
#include <vector>
#include <unordered_set>
#include <functional>
#include <algorithm>

using namespace std;

int solution(vector<int> info, vector<vector<int>> edges)
{
    int vsize = info.size();

    auto isWolf = [&info](int v) { return info[v]; };

    vector<vector<int>> adj(vsize);

    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // vector<vector<vector<int>>> visited(
    //     vsize, vector<vector<int>>(vsize, vector<int>(vsize)));

    vector<int> visited(vsize);
    visited[0] = 1;
    int maxSheep = 1;

    // unordered_set<int> available;
    int sheep = 1;
    int wolf = 0;

    auto canChoose = [&](int v)
    { return isWolf(v) ? sheep - wolf - 1 > 0 : sheep + 1 - wolf > 0; };

    // 이전노드, 현재노드
    function<void(int, unordered_set<int>)> dfs =
        [&](int cv, unordered_set<int> available)
    {
        maxSheep = max(maxSheep, sheep);

        available.erase(cv);
        for (int nv : adj[cv])
        {
            if (!visited[nv])
                available.insert(nv);
        }

        for (int av : available)
        {
            if (visited[av] || !canChoose(av))
                continue;

            if (isWolf(av))
                wolf++;
            else
                sheep++;

            visited[av] = 1;
            dfs(av, available);
            visited[av] = 0;

            if (isWolf(av))
                wolf--;
            else
                sheep--;
        }
    };

    dfs(0, unordered_set<int>());

    return maxSheep;
}


#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
    using P = pair<int, int>; // 가중치, 노드

    int INF = 1e9;
    vector<int> answer{-1, INF};

    unordered_set<int> gateSet(gates.begin(), gates.end());
    unordered_set<int> summitSet(summits.begin(), summits.end());

    vector<vector<P>> adj(n + 1);
    for (const auto &path : paths)
    {
        int u = path[0];
        int v = path[1];
        int w = path[2];

        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }

    vector<int> intensity(n + 1, INF);
    priority_queue<P, vector<P>, greater<P>> pq;

    for (int g : gates)
    {
        intensity[g] = 0;
        pq.push({0, g});
    }

    while (!pq.empty())
    {
        auto [cw, cv] = pq.top();
        pq.pop();

        if (cw > intensity[cv])
            continue;

        if (summitSet.count(cv))
            continue;

        for (auto [w, nv] : adj[cv])
        {
            int nw = max(cw, w);

            if (nw < intensity[nv])
            {
                intensity[nv] = nw;
                pq.push({nw, nv});
            }
        }
    }

    sort(summits.begin(), summits.end());

    for (int s : summits)
    {
        if (intensity[s] < answer[1])
        {
            answer[0] = s;
            answer[1] = intensity[s];
        }
    }

    return answer;
}

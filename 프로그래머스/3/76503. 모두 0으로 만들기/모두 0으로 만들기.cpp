#include <string>
#include <vector>
#include <functional>

using namespace std;

long long solution(vector<int> a, vector<vector<int>> edges)
{
    using ll = long long;

    ll answer = 0;
    int size = a.size();

    vector<ll> dp(size);
    vector<bool> visited(size);

    vector<vector<int>> adj(size);

    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    function<ll(int)> weightRec = [&](int cv)
    {
        ll result = a[cv];

        for (auto nv : adj[cv])
        {
            if (!visited[nv])
            {
                visited[nv] = true;
                result += weightRec(nv);
            }
        }

        return dp[cv] = result;
    };

    visited[0] = true;
    weightRec(0);

    if (dp[0] != 0)
        return -1;

    for (int i = 0; i < size; i++)
    {
        answer += abs(dp[i]);
    }

    return answer;
}

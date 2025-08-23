#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> wires)
{
    int answer = n;

    vector<vector<int>> adj(n + 1);

    for (auto wire : wires)
    {
        int u = wire[0];
        int v = wire[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> subtreeSize(n + 1);

    function<void(int)> setSize = [&](int u)
    {
        subtreeSize[u] = 1;

        for (int v : adj[u])
        {
            if (!subtreeSize[v])
            {
                setSize(v);
                subtreeSize[u] += subtreeSize[v];
            }
        }
    };

    setSize(1);

    for (int i = 1; i <= n; i++)
    {
        answer = min(answer, abs(n - 2 * subtreeSize[i]));
    }

    return answer;
}

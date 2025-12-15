#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;
    // 거리, 노드
    using P = pair<long long, int>;

    vector<vector<P>> adj(N + 1);

    for (auto roadInfo : road)
    {
        int u = roadInfo[0];
        int v = roadInfo[1];
        int c = roadInfo[2];

        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }

    vector<long long> dist(N + 1, 1e11);

    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while (!q.empty())
    {
        int cv = q.front();
        q.pop();

        for (auto [c, nv] : adj[cv])
        {
            if (dist[nv] > dist[cv] + c)
            {
                dist[nv] = dist[cv] + c;
                q.push(nv);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (dist[i] <= K)
            answer++;
    }

    return answer;
}

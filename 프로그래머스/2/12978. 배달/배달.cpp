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

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    while (!pq.empty())
    {
        auto [cC, cV] = pq.top();
        pq.pop();

        for (auto [nC, nV] : adj[cV])
        {
            if (dist[nV] > dist[cV] + nC)
            {
                dist[nV] = dist[cV] + nC;
                pq.push({dist[nV], nV});
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

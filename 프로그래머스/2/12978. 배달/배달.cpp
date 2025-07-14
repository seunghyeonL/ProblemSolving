#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int>> road, int K)
{
    using P = pair<long long, int>;
		
    int answer = 0;

    vector<vector<P>> adjList(
        N + 1, vector<P>());
    vector<long long> dist(N + 1, 500001);
    dist[1] = 0;

    for (auto data : road)
    {
        int u = data[0], v = data[1];
        long long load = data[2];
        adjList[u].push_back({load, v});
        adjList[v].push_back({load, u});
    }

    priority_queue<P, vector<P>, greater<P>> pq; // 거리, 노드
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [curDist, curNode] = pq.top();
        pq.pop();

        if (curDist != dist[curNode])
            continue;

        for (auto [nextDistDiff, nextNode] : adjList[curNode])
        {
            if (dist[curNode] + nextDistDiff < dist[nextNode])
            {
                dist[nextNode] = dist[curNode] + nextDistDiff;
                pq.push({dist[nextNode], nextNode});
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
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;

    vector<vector<pair<long long, int>>> adjList(
        N + 1, vector<pair<long long, int>>(1, {-1, -1}));
    vector<long long> dist(N + 1, 500001);
    dist[1] = 0;

    for (auto data : road)
    {
        int u = data[0], v = data[1];
        long long load = data[2];
        adjList[u].push_back({load, v});
        adjList[v].push_back({load, u});
    }

    // for (int i = 0; i <= N; i++)
    // {
    //     cout << "i: " << i << " ";
    //     printp(adjList[i]);
    // }
    // cout << "\n\n";

    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq{greater<pair<long long, int>>()}; // 거리, 노드
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [curDist, curNode] = pq.top();
        pq.pop();

        // cout << "curDist: " << curDist << " curNode: " << curNode << '\n';
        // prints(dist);

        if (curDist != dist[curNode])
            continue;

        for (auto [nextDistDiff, nextNode] : adjList[curNode])
        {
            if (nextNode == -1)
                continue;
            if (dist[curNode] + nextDistDiff < dist[nextNode])
            {
                dist[nextNode] = dist[curNode] + nextDistDiff;
                // cout << "nextDist: " << dist[nextNode]
                //      << " nextNode: " << nextNode << '\n';
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    // prints(dist);

    for (int i = 1; i <= N; i++)
    {
        if (dist[i] <= K)
            answer++;
    }

    return answer;
}
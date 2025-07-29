#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    using ll = long long;
    
    vector<int> answer;
    
    unordered_map<int, int> sourceMap;
    for (int source : sources)
    {
        sourceMap.insert({source, -1});
    }
    
    
    // 인접리스트
    vector<vector<int>> adj(n + 1);
    for (auto road : roads)
    {
        int u = road[0];
        int v = road[1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // 도착점 큐에 넣기
    queue<int> q;
    vector<ll> dist(n + 1, -1);
    q.push(destination);
    dist[destination] = 0;
    
    // bfs    
    while(!q.empty())
    {
        int cV = q.front();
        q.pop();
        
        if (sourceMap.find(cV) != sourceMap.end())
        {
            sourceMap[cV] = dist[cV];
        }
        
        for (int nV : adj[cV])
        {
            if (dist[nV] == -1)
            {
                q.push(nV);
                dist[nV] = dist[cV] + 1;
            }
        }
    }
    
    for (int source : sources)
    {
        answer.push_back(sourceMap[source]);
    }
    
    return answer;
}
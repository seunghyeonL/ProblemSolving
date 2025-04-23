#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <functional>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int result = 0;
    
    vector<vector<pair<int, int>>> adj(n); // {비용, 노드}
    
    for(auto edgeCost : costs)
    {
        int u = edgeCost[0];
        int v = edgeCost[1];
        int cost = edgeCost[2];
        
        adj[u].push_back({cost, v});
        adj[v].push_back({cost, u});
    }
    
    priority_queue<
        tuple<int, int, int>, 
        vector<tuple<int, int, int>>, 
        greater<tuple<int, int, int>>
            > pq;
    
    vector<bool> connected(n, false);
    int connectedNum  = 0;
    
    connected[0] = true;
    connectedNum++;
    for(auto [cost, v] : adj[0])
    {
        pq.push({cost, 0, v});
    }
    
    while(connectedNum < n)
    {
        auto [cost, u, v] = pq.top();
        pq.pop();
        
        // 이미 연결된 상태 건너뛰기
        if(connected[v]) continue;
        
        // 연결하기
        result += cost;
        connected[v] = true;
        connectedNum++;
        
        // pq에 새로 연결된 노드의 edge들 추가
        for(auto [nextCost, nextV] : adj[v])
        {
            if(connected[nextV]) continue;
            pq.push({nextCost, v, nextV});
        }
    }
    
    
    return result;
}
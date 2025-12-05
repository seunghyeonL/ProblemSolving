#include <bits/stdc++.h>
using namespace std;

// 다익스트라로 출발점에서 산봉우리마다 intensity 체크
// 최소 intensity 경로 찾기

using P = pair<int, int>;
const int INF = 1e9;
const int NMX = 50000;
int N;
vector<P> adj[NMX + 1];
int I[NMX + 1];


vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) 
{
    N = n;
    sort(summits.begin(), summits.end());
    
    for (const auto& path : paths)
    {
        int u = path[0];
        int v = path[1];
        int w = path[2];
        
        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }
    
    fill(I, I + N + 1, INF);
    priority_queue<P, vector<P>, greater<P>> pq; // i, v
    
    for (int sv : gates)
    {
        I[sv] = 0;
        pq.emplace(0, sv);
    }
    
    while (!pq.empty())
    {
        auto [i, cv] = pq.top();
        pq.pop();
        
        if (i > I[cv]) continue;
        
        for (auto [w, nv] : adj[cv])
        {
            if (I[nv] > max(w, i))
            {
                I[nv] = max(w, i);
                
                if (!binary_search(summits.begin(), summits.end(), nv))
                    pq.emplace(I[nv], nv);
            }
        }
    }
    
    int mn_i = INF;
    int mn_v = 0;
    
    for (int ev : summits)
    {
        if (mn_i > I[ev])
        {
            mn_i = I[ev];
            mn_v = ev;
        }
    }
    
    return {mn_v, mn_i};
}
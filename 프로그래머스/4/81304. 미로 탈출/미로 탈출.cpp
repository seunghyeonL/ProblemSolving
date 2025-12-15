#include <bits/stdc++.h>
using namespace std;

// 간선 가중치 존재 -> 다익스트라
// 상태 : cv, 함정방 상태(바뀌었는가 아닌가; 함정 방이 아닌 경우는 0만 사용)

using T3 = tuple<long long, int, int>;

const int NMX = 1000;
const long long INF = 1e18;
const int TMX = 10;

int N, T;
int sv, ev;

vector<int> traps;
int trap_idx[NMX + 1];

// w, v, 이동 가능 여부
vector<tuple<int, int, int>> adj[NMX + 1];

// dist[u] : sv -> u 최단거리
long long dist[NMX + 1][1 << TMX];

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> _traps) 
{
    traps = _traps;
    
    N = n;
    T = traps.size();
    sv = start;
    ev = end;
    
    fill(trap_idx, trap_idx + N + 1, -1);
    fill(adj, adj + N + 1, vector<tuple<int, int, int>>());
    fill(&dist[0][0], &dist[0][0] + (NMX + 1) * (1 << TMX), INF);

    for (auto& road : roads)
    {
        int u = road[0];
        int v = road[1];
        int w = road[2];
        
        adj[u].emplace_back(w, v, 1);
        adj[v].emplace_back(w, u, 0);
    }
    
    for (int i = 0 ; i < T ; i++)
    {
        trap_idx[traps[i]] = i;
    }
    
    // sv로 부터 최단 거리, cv, trap mask
    priority_queue<T3, vector<T3>, greater<T3>> pq;
    
    pq.emplace(0, sv, 0);
    dist[sv][0] = 0;
    
    long long ans = 0;
    while (!pq.empty())
    {
        auto [d, cv, mask] = pq.top();
        pq.pop();
        
        if (d > dist[cv][mask]) 
            continue;
        
        if (cv == ev) 
        {
            ans = d;
            break;
        }
        
        int active_cv = 0;
        if (trap_idx[cv] != -1)
        {
            int ti = trap_idx[cv];
            active_cv = (mask >> ti) & 1;
        }
        
        for (auto [w, nv, can_move] : adj[cv])
        {   
            if (trap_idx[nv] == -1)
            {
                can_move ^= active_cv;
                
                if (!can_move) 
                    continue;
                
                if (dist[nv][mask] > d + w)
                {
                    dist[nv][mask] = d + w;
                    pq.emplace(d + w, nv, mask);
                }
            }
            else
            {
                int ti = trap_idx[nv];
                int active_nv = (mask >> ti) & 1;
                
                can_move ^= active_cv;
                can_move ^= active_nv;
                
                if (!can_move) 
                    continue;
                
                int n_mask = mask ^ (1 << ti);
                
                if (dist[nv][n_mask] > d + w)
                {
                    dist[nv][n_mask] = d + w;
                    pq.emplace(d + w, nv, n_mask);
                }
            }
        }
    }
    
    return ans;
}
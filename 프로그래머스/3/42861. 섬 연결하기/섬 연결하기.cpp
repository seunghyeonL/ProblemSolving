#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 간선간 비용 o
// MST
// 노드 0부터 시작

const int NMX = 100;
int N;
int uf[NMX];

int find_root(int u)
{
    if (uf[u] < 0) 
        return u;
    
    return uf[u] = find_root(uf[u]);
}

bool union_set(int u, int v)
{
    u = find_root(u);
    v = find_root(v);
    
    if (u == v) 
        return false;
    
    // u -> v
    if (uf[u] < uf[v]) swap(u, v);
    
    uf[v] += uf[u];
    uf[u] = v;
    
    return true;
}

int solution(int n, vector<vector<int>> costs) 
{
    N = n;
    memset(uf, -1, sizeof(uf));
    
    // ---
    
    sort(costs.begin(), costs.end(), [](const auto& a, const auto& b){
        return a[2] < b[2];
    });
    
    ll ans = 0;
    int cnt = 0; // 연결 개수
    for (const auto& cost : costs)
    {
        int u = cost[0];
        int v = cost[1];
        int w = cost[2];
        
        if (union_set(u, v))
        {
            ans += w;
            cnt++;
        }
        
        if (cnt == N - 1)
            break;
    }

    return ans;
}
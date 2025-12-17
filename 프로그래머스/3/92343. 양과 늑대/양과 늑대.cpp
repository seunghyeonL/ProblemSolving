#include <bits/stdc++.h>
using namespace std;

// 현재 방문한 노드 상태가 필요
// 방문한 양 수가 늑대 수보다 커야함

const int NMX = 17;
int N;
vector<int> adj[NMX];

vector<int> info;
vector<bool> vis;

int dfs(int sn, int wn)
{
    int ret = sn;

    for (int pv = 0 ; pv < N ; pv++)
    {
        if (!vis[pv])
            continue;
        
        for (int nv : adj[pv])
        {
            if (vis[nv])
                continue;
            
            bool is_wolf = info[nv];
            
            if (!is_wolf)
            {
                vis[nv] = true;
                ret = max(ret, dfs(sn + 1, wn));
                vis[nv] = false;
            }
            else if (sn > wn + 1)
            {
                vis[nv] = true;
                ret = max(ret, dfs(sn, wn + 1));
                vis[nv] = false;
            }
        }
    }
    
    return ret;
}

int solution(vector<int> _info, vector<vector<int>> edges) 
{
    info = _info;
    N = info.size();
    vis.resize(N);
    
    for (auto& edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        
        adj[u].push_back(v);
    }
    
    vis[0] = true;
    int ans = dfs(1, 0);
    vis[0] = false;
    
    return ans;
}
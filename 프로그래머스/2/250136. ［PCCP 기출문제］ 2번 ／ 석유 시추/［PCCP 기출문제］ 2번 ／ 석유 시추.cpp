#include <bits/stdc++.h>
using namespace std;

// union by size

const int NMX = 500;
int N, M;
int uf[NMX * NMX];

int get_node_num(int x, int y)
{
    return M * x + y;
}

bool is_valid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

vector<pair<int, int>> moves
{
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

int find_root(int u)
{
    if (uf[u] < 0) return u;
    return uf[u] = find_root(uf[u]);
}

bool union_set(int u, int v)
{
    u = find_root(u);
    v = find_root(v);
    
    if (u == v) return false;
    
    // u -> v
    if (uf[u] < uf[v]) swap(u, v);
    
    uf[v] = uf[u] + uf[v];
    uf[u] = v;
    
    return true;
}


int solution(vector<vector<int>> land) {
    N = land.size();
    M = land[0].size();
    memset(uf, -1, sizeof(uf));
    
    for (int x = 0 ; x < N ; x++)
        for (int y = 0 ; y < M ; y++)
        {
            if (!land[x][y]) continue;
            
            int u = get_node_num(x, y);
            for (auto [dx, dy] : moves)
            {
                int nx = x + dx;
                int ny = y + dy;
                
                if (!is_valid(nx, ny) || !land[nx][ny]) continue;
                
                int v = get_node_num(nx, ny);
                
                union_set(u, v);
            }
        }
            
    int ans = 0;
    for (int y = 0 ; y < M ; y++)
    {
        vector<int> cand;
        for (int x = 0 ; x < N ; x++)
        {
            int u = get_node_num(x, y);
            u = find_root(u);
            
            if (land[u / M][u % M])
                cand.push_back(u);
        }
        
        sort(cand.begin(), cand.end());
        cand.erase(unique(cand.begin(), cand.end()), cand.end());
        
        int sum = 0;
        for (int u : cand)
        {
            sum += -uf[u];
        }
        
        ans = max(ans, sum);
    }
    
    return ans;
}
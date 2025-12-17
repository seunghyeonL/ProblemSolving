#include <bits/stdc++.h>
using namespace std;

const int NMX = 500;
int N, M;
vector<vector<int>> land;
int vis[NMX][NMX]; // 클러스터 네이밍
vector<int> c_size{0};
int c_num;

vector<pair<int, int>> moves
{
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

bool is_valid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

void bfs(int sx, int sy)
{
    c_num++;
    int c_c_size = 0;
    
    queue<pair<int, int>> q;
    q.emplace(sx, sy);
    vis[sx][sy] = c_num;
    
    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();
        
        c_c_size++;
        
        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;
            
            if (!is_valid(nx, ny) || !land[nx][ny] || vis[nx][ny])
                continue;
            
            vis[nx][ny] = c_num;
            q.emplace(nx, ny);
        }
    }
    
    c_size.push_back(c_c_size);
}

int solution(vector<vector<int>> _land) 
{
    land = _land;
    N = land.size();
    M = land[0].size();
    
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < M ; j++)
        {
            if (land[i][j] && !vis[i][j])
                bfs(i, j);
        }
    
    int ans = 0;
    for (int j = 0 ; j < M ; j++)
    {
        int cur = 0;
        vector<int> cand;
        
        for (int i = 0 ; i < N ; i++)
        {
            int n = vis[i][j];
            
            if (n)
                cand.push_back(n);
        }
        
        sort(cand.begin(), cand.end());
        cand.erase(unique(cand.begin(), cand.end()), cand.end());
        
        for (int n : cand)
        {
            cur += c_size[n];
        }
        
        ans = max(ans, cur);
    }
    
    return ans;
}
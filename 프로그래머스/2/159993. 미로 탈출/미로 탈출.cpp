#include <bits/stdc++.h>
using namespace std;

int N, M;
int dist[100][100];

void reset_dist()
{
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < M ; j++)
            dist[i][j] = -1;
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

void bfs(int sx, int sy, int ex, int ey, const vector<string>& maps)
{
    reset_dist();
    
    queue<pair<int, int>> q;
    dist[sx][sy] = 0;
    q.emplace(sx, sy);
    
    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();
        
        if (cx == ex && cy == ey) break;
        
        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;
            
            if (is_valid(nx, ny) && maps[nx][ny] != 'X' && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[cx][cy] + 1;
                q.emplace(nx, ny);
            }
        }
    }
}

int solution(vector<string> maps) {
    N = maps.size();
    M = maps[0].size();
    
    int sx, sy, lx, ly, ex, ey;
    
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < M; j++)
        {
            if (maps[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            else if (maps[i][j] == 'L')
            {
                lx = i;
                ly = j;
            }
            else if (maps[i][j] == 'E')
            {
                ex = i;
                ey = j;
            }
        }
    
    int ans = 0;
    bfs(sx, sy, lx, ly, maps);
    if (dist[lx][ly] < 0)
        return -1;
    
    ans += dist[lx][ly];
    
    bfs(lx, ly, ex, ey, maps);
    if (dist[ex][ey] < 0)
        return -1;
    
    ans += dist[ex][ey];
    
    return ans;
   
}
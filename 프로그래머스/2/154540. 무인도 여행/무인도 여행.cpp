#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

// 연결 가중치 x
// bfs로 cluster naming, 식량 수 배열 구성 -> ans

const int LMT = 100;
vector<string> maps;

int N, M;
bool vis[LMT][LMT];

vector<P> moves
{
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

bool is_valid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

// 덩어리 식량 합 반환
int bfs(int sx, int sy)
{
    queue<P> q;
    q.emplace(sx, sy);
    vis[sx][sy] = true;
    
    int ret = 0;
    
    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();
        
        ret += maps[cx][cy] - '0';
        
        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;
            
            if (!is_valid(nx, ny) || vis[nx][ny] || maps[nx][ny] == 'X')
                continue;
            
            q.emplace(nx, ny);
            vis[nx][ny] = true;
        }
    }
    
    return ret;
}

vector<int> solution(vector<string> _maps) 
{
    maps = _maps;
    N = maps.size();
    M = maps[0].size();
    memset(vis, false, sizeof(vis));
    
    vector<int> ans;
    
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < M ; j++)
        {
            if (!vis[i][j] && maps[i][j] != 'X')
            {
                ans.push_back(bfs(i, j));
            }
        }
    
    sort(ans.begin(), ans.end());
    
    if (ans.empty())
        ans.push_back(-1);
    
    return ans;
}
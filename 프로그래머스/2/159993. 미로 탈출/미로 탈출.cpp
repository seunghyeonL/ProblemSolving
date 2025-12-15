#include <bits/stdc++.h>
using namespace std;

const int MX = 100;
int N, M;

vector<string> board;
int dist[MX][MX];



vector<pair<int, int>> moves
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

int bfs(pair<int, int> sv, pair<int, int> ev)
{
    memset(dist, -1, sizeof(dist));
    
    auto [sx, sy] = sv;
    auto [ex, ey] = ev;
    
    queue<pair<int, int>> q;
    q.push(sv);
    dist[sx][sy] = 0;
    
    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();
        
        if (cx == ex && cy == ey)
            break;
        
        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;
            
            if (!is_valid(nx, ny) || board[nx][ny] == 'X' || dist[nx][ny] != -1)
                continue;
            
            q.emplace(nx, ny);
            dist[nx][ny] = dist[cx][cy] + 1;
        }
    }
    
    return dist[ex][ey];
}

int solution(vector<string> _maps) 
{
    board = _maps;
    N = board.size();
    M = board[0].size();
    
    pair<int, int> sv, ev, lv;
    
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < M ; j++)
        {
            if (board[i][j] == 'S')
                sv = {i, j};
            else if (board[i][j] == 'E')
                ev = {i, j};
            else if (board[i][j] == 'L')
                lv = {i, j};
        }
    
    int d1 = bfs(sv, lv);
    if (d1 < 0) return -1;
    int d2 = bfs(lv, ev);
    if (d2 < 0) return -1;
    
    return d1 + d2;
}
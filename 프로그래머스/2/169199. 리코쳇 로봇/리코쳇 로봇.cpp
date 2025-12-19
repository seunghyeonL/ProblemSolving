#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

// 이동에 가중치 x -> bfs

const int LMT = 100;
int N, M;
vector<string> board;
int sx, sy, ex, ey;
int dist[LMT][LMT];

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

int solution(vector<string> _board) 
{
    board = _board;
    N = board.size();
    M = board[0].size();
    memset(dist, -1, sizeof(dist));
    
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < M ; j++)
        {
            if (board[i][j] == 'R')
            {
                sx = i;
                sy = j;
            }
            else if (board[i][j] == 'G')
            {
                ex = i;
                ey = j;
            }
        }
    
    queue<P> q;
    q.emplace(sx, sy);
    dist[sx][sy] = 0;
    
    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();
        
        if (cx == ex && cy == ey)
            break;
        
        for (auto [dx, dy] : moves)
        {
            int nx = cx;
            int ny = cy;
            
            while (is_valid(nx + dx, ny + dy) && board[nx + dx][ny + dy] != 'D')
            {
                nx += dx;
                ny += dy;
            }
            
            if (dist[nx][ny] == -1)
            {
                q.emplace(nx, ny);
                dist[nx][ny] = dist[cx][cy] + 1;
            }
        }
    }
    
    return dist[ex][ey];
}
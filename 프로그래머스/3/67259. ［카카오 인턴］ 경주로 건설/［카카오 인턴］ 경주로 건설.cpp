#include <bits/stdc++.h>

using namespace std;
using T = tuple<int, int, int, int>;

const int INF = 1e9;
int dist[25][25][4];
int N;

bool is_valid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}

vector<pair<int, int>> moves
{
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

int solution(vector<vector<int>> board) {
    N = board.size();
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < N ; j++)
            for (int dir = 0 ; dir < 4 ; dir++)
                dist[i][j][dir] = INF;
    
    priority_queue<T, vector<T>, greater<T>> pq; // d, x, y, dir
    
    dist[0][0][0] = 0;
    dist[0][0][2] = 0;
    pq.emplace(0, 0, 0, 0);
    pq.emplace(0, 0, 0, 2);
    
    while (!pq.empty())
    {
        auto [d, cx, cy, cd] = pq.top();
        pq.pop();
        
        if (cx == N - 1 && cy == N - 1) break;
        
        if (dist[cx][cy][cd] < d) continue;
        
        for (int nd = 0 ; nd < 4 ; nd++)
        {
            auto [dx, dy] = moves[nd];
            int nx = cx + dx;
            int ny = cy + dy;
          
            int w = (cd == nd ? 100 : 600);
                
            if (is_valid(nx, ny) && !board[nx][ny] && dist[nx][ny][nd] > d + w)
            {
                dist[nx][ny][nd] = d + w;
                pq.emplace(d + w, nx, ny, nd);
            }
        }
    }
    
    return min(dist[N - 1][N - 1][0], dist[N - 1][N - 1][2]);
}
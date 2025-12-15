#include <bits/stdc++.h>
using namespace std;
using T = tuple<int, int, int, int>;
using P = pair<int, int>;

// 직선으로 연결할때와 꺾을때 비용이 다름
// => 다익스트라

const int INF = 1e9;
const int NMX = 25;
vector<vector<int>> board;
int N;

// dist[x][y][dir] : x, y에 dir방향으로 들어오는 경로 최단거리
int dist[NMX][NMX][4]; 

enum D { R, D, L, U };

vector<P> moves
{
    {0, 1}, // R
    {1, 0}, // D
    {0, -1}, // L
    {-1, 0}, // U
};

bool is_valid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}

void dijkstra()
{
    // mn_cost, x, y, dir
    priority_queue<T, vector<T>, greater<T>> pq;
    
    pq.emplace(0, 0, 0, D); // D
    pq.emplace(0, 0, 0, R); // R
    dist[0][0][D] = 0;
    dist[0][0][R] = 0;
    
    while (!pq.empty())
    {
        auto [cost, cx, cy, c_dir] = pq.top();
        pq.pop();
        
        if (cost > dist[cx][cy][c_dir])
            continue;
        
        if (cx == N - 1 && cy == N - 1) 
            break;
        
        for (int dir = 0 ; dir < 4 ; dir++)
        {
            auto [dx, dy] = moves[dir];
            int nx = cx + dx;
            int ny = cy + dy;
            
            if (!is_valid(nx, ny) || board[nx][ny]) continue;
            
            int cw = (dir == c_dir ? 100 : 600);
            
            if (dist[nx][ny][dir] > cost + cw)
            {
                dist[nx][ny][dir] = cost + cw;
                pq.emplace(cost + cw, nx, ny, dir);
            }
        }
    }
}

int solution(vector<vector<int>> _board) 
{
    board = _board;
    N = board.size();
    fill(&dist[0][0][0], &dist[0][0][0] + NMX * NMX * 4, INF);
    
    dijkstra();

    return min(dist[N - 1][N - 1][R], dist[N - 1][N - 1][D]);
}
#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using T = tuple<int, int, int, int>;


// NMX == 25
// 가중치가 다름 -> 다익스트라
// 연결시 이전에 연결한 방향 상태가 필요

const int INF = 1e9;
const int NMX = 25;
int N;
vector<vector<int>> board;

enum Dir { D, U, R, L};
vector<P> moves
{
    {1, 0}, // D
    {-1, 0}, // U
    {0, 1}, // R
    {0, -1}, // L
};

// dir는 (x, y)로 들어오는 방향
// (0, 0, D or R) ->  (x, y, dir) 까지 연결 최소 cost
int dist[NMX][NMX][4];

bool is_valid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}

int solution(vector<vector<int>> _board) 
{
    board = _board;
    N = board.size();
    fill(&dist[0][0][0], &dist[0][0][0] + NMX * NMX * 4, INF);
    
    // cost, x, y, dir
    priority_queue<T, vector<T>, greater<T>> pq;
    
    dist[0][0][D] = 0;
    dist[0][0][R] = 0;
    
    pq.emplace(0, 0, 0, D);
    pq.emplace(0, 0, 0, R);
    
    int ans = 0;
    
    while (!pq.empty())
    {
        auto [cw, cx, cy, cd] = pq.top();
        pq.pop();
        
        if (cw > dist[cx][cy][cd]) 
            continue;
        
        if (cx == N - 1 && cy == N - 1)
        {
            ans = cw;
            break;
        }
        
        for (int nd = 0 ; nd < 4 ; nd++)
        {
            auto [dx, dy] = moves[nd];
            int nx = cx + dx;
            int ny = cy + dy;
            
            if (!is_valid(nx, ny) || board[nx][ny] == 1)
                continue;
            
            int dw = cd == nd ? 100 : 600;
            int nw = cw + dw;
            
            if (dist[nx][ny][nd] > nw)
            {
                dist[nx][ny][nd] = nw;
                pq.emplace(nw, nx, ny, nd);
            }
        }
    }

    return ans;
}
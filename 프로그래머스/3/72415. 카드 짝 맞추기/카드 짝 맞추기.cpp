#include <bits/stdc++.h>
using namespace std;

// 모든 이동이 가중치 1 -> bfs
// 현재 위치에서 없앨 카드를 하나 고르고 
// cv -> card_pos1 -> card_pos2, cv -> card_pos2 -> card_pos1로 상태 분기
// 백트래킹

const int N = 4;
vector<vector<int>> board;
int C; // 카드 개수

bool card_remain[7];
vector<pair<int, int>> card_pos[7];

int dist[N][N];
bool is_card[N][N];

vector<pair<int, int>> moves
{
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

bool is_valid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}

int bfs(int sx, int sy, int ex, int ey)
{
    memset(dist, -1, sizeof(dist));
    
    queue<pair<int, int>> q;
    
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
            int nx = cx + dx;
            int ny = cy + dy;
            
            if (!is_valid(nx, ny))
                continue;
            
            if (dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[cx][cy] + 1;
                q.emplace(nx, ny);
            }
            
            int nx2 = nx;
            int ny2 = ny;
            
            while (!is_card[nx2][ny2] && is_valid(nx2 + dx, ny2 + dy))
            {
                nx2 += dx;
                ny2 += dy;
            }
            
            if (dist[nx2][ny2] == -1)
            {
                dist[nx2][ny2] = dist[cx][cy] + 1;
                q.emplace(nx2, ny2);
            }
        }
    }
    
    return dist[ex][ey];
}

void bt(int cx, int cy, int cur_cost, int& ans)
{   
    if (C == 0)
    {
        ans = min(cur_cost, ans);
        return;
    }
    
    for (int card = 1 ; card <= 6 ; card++)
    {
        if (!card_remain[card])
            continue;
        
        auto [tx1, ty1] = card_pos[card][0];
        auto [tx2, ty2] = card_pos[card][1];
        
        int cost1 = bfs(cx, cy, tx1, ty1) + bfs(tx1, ty1, tx2, ty2) + 2;
        int cost2 = bfs(cx, cy, tx2, ty2) + bfs(tx2, ty2, tx1, ty1) + 2;
        
        C--;
        card_remain[card] = false;
        is_card[tx1][ty1] = false;
        is_card[tx2][ty2] = false;
        
        bt(tx1, ty1, cur_cost + cost2, ans);
        bt(tx2, ty2, cur_cost + cost1, ans);
        
        C++;
        card_remain[card] = true;
        is_card[tx1][ty1] = true;
        is_card[tx2][ty2] = true;
    }
}

int solution(vector<vector<int>> _board, int r, int c) 
{
    board = _board;
    for (auto& el : card_pos)
        el.clear();
    
    memset(card_remain, false, sizeof(card_remain));
    memset(is_card, false, sizeof(is_card));
    
    
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < N ; j++)
        {
            if (board[i][j])
            {
                int card = board[i][j];
                
                is_card[i][j] = true;
                card_pos[card].emplace_back(i, j);
                card_remain[card] = true;
            }
        }
    
    for (int i = 1 ; i <= 6 ; i++)
    {
        if (card_remain[i])
            C++;
    }
    
    int ans = 10000;
    bt(r, c, 0, ans);
    
    return ans;
}
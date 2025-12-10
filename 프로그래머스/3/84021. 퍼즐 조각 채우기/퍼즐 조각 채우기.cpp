#include <bits/stdc++.h>
using namespace std;

const int NMX = 50;
int N;

int blanks_sz;
int blocks_sz;

vector<pair<int, int>> blanks[NMX * NMX];
vector<pair<int, int>> blocks[NMX * NMX][4];
bool vis[NMX][NMX];
bool used[NMX * NMX];

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

void normalize(vector<pair<int, int>>& block)
{
    sort(block.begin(), block.end());
    
    auto [fx, fy] = block[0];
    
    for (auto& [bx, by] : block)
    {
        bx -= fx;
        by -= fy;
    }
}

void set_blank(int sx, int sy, const vector<vector<int>>& board)
{
    vector<pair<int, int>> blank;
    
    queue<pair<int, int>> q;
    q.emplace(sx, sy);
    vis[sx][sy] = true;
    
    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();
        
        blank.emplace_back(cx, cy);
        
        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;
            
            if (is_valid(nx, ny) && !board[nx][ny] && !vis[nx][ny])
            {
                q.emplace(nx, ny);
                vis[nx][ny] = true;
            }
        }
    }
    
    normalize(blank);
    blanks[blanks_sz++] = blank;
}

// 반시계 90도 회전
void rotate_90(vector<pair<int, int>>& block)
{
    /*
    
    (x') = (c, -s)(x)
    (y') = (s,  c)(y)
    (x') = (0, -1)(x)
    (y') = (1,  0)(y)
    
    x' == -y
    y' == x
    
    */
    
    for (auto& [bx, by] : block)
    {
        swap(bx, by);
        bx *= -1;
    }
}

void set_block(int sx, int sy, const vector<vector<int>>& table)
{
    vector<pair<int, int>> block;
    
    queue<pair<int, int>> q;
    q.emplace(sx, sy);
    vis[sx][sy] = true;
    
    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();
        
        block.emplace_back(cx, cy);
        
        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;
            
            if (is_valid(nx, ny) && table[nx][ny] && !vis[nx][ny])
            {
                q.emplace(nx, ny);
                vis[nx][ny] = true;
            }
        }
    }
    
    normalize(block);
    blocks[blocks_sz][0] = block;
    
    for (int i = 1 ; i <= 3 ; i++)
    {
        rotate_90(block);
        normalize(block);
        blocks[blocks_sz][i] = block;
    }
    
    blocks_sz++;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) 
{
    N = game_board.size();
    blanks_sz = 0;
    blocks_sz = 0;

    fill(blanks, blanks + NMX * NMX, vector<pair<int,int>>());
    fill(&blocks[0][0], &blocks[0][0] + NMX + NMX * 4, vector<pair<int,int>>());
    memset(used, false, sizeof(used));
    
    memset(vis, false, sizeof(vis));
    for (int i = 0 ; i < N; i++)
        for (int j = 0 ; j < N; j++)
        {
            if (!game_board[i][j] && !vis[i][j])
            {
                set_blank(i, j, game_board);
            }
        }
    
    
    memset(vis, false, sizeof(vis));
    for (int i = 0 ; i < N; i++)
        for (int j = 0 ; j < N; j++)
        {
            if (table[i][j] && !vis[i][j])
            {
                set_block(i, j, table);
            }
        }
    
    int ans = 0;
    for (int i = 0 ; i < blanks_sz ; i++)
    {
        const auto& blank = blanks[i];
        
        bool found = false;
        for (int j = 0 ; j < blocks_sz && !found ; j++)
        {
            if (used[j]) continue;
            
            for (int r = 0 ; r < 4 ; r++)
            {
                const auto& block = blocks[j][r];
                    
                if (blank == block)
                {
                    found = true;
                    used[j] = true;
                    ans += block.size();
                    break;
                }
            }
        }
    }
    
    return ans;
}
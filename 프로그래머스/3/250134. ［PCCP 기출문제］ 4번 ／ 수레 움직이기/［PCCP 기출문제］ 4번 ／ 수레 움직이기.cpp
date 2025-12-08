#include <bits/stdc++.h>
using namespace std;

const int MX = 4;
int N, M;

// 0 : blue, 1 : red
pair<int, int> sv[2];
pair<int, int> ev[2];
// pair<int, int> cv[2];

vector<vector<int>> board;
bool vis[2][MX][MX];

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

void dfs(pair<int, int> cv0, pair<int, int> cv1, int ct, int& ans)
{
    if (cv0 == ev[0] && cv1 == ev[1])
    {
        ans = min(ans, ct);
        return;
    }
    
    auto [cx0, cy0] = cv0;
    auto [cx1, cy1] = cv1;
    
    vector<pair<int, int>> nvs0;
    vector<pair<int, int>> nvs1;
    
    if (cv0 != ev[0])
    {
        for (auto [dx0, dy0] : moves)
        {
            int nx0 = cx0 + dx0;
            int ny0 = cy0 + dy0;
            auto nv0 = make_pair(nx0, ny0);
            
            if (!is_valid(nx0, ny0) || vis[0][nx0][ny0] || board[nx0][ny0] == 5)
                continue;
            
            nvs0.push_back(nv0);
        }
    }
    else
    {
        nvs0.push_back({cx0, cy0});
    }
    
    if (cv1 != ev[1])
    {
        for (auto [dx1, dy1] : moves)
        {
            int nx1 = cx1 + dx1;
            int ny1 = cy1 + dy1;
            auto nv1 = make_pair(nx1, ny1);

            if (!is_valid(nx1, ny1) || vis[1][nx1][ny1] || board[nx1][ny1] == 5)
                continue;

            nvs1.push_back(nv1);
        }
    }
    else
    {
        nvs1.push_back({cx1, cy1});
    }
    
    for (const auto& nv0 : nvs0)
    {
        for (const auto& nv1 : nvs1)
        {
            if (nv0 == nv1) continue;
            if (nv0 == cv1 && nv1 == cv0) continue;
            
            vis[0][nv0.first][nv0.second] = true;
            vis[1][nv1.first][nv1.second] = true;
            
            dfs(nv0, nv1, ct + 1, ans);
            
            vis[0][nv0.first][nv0.second] = false;
            vis[1][nv1.first][nv1.second] = false;
        }
    }
}

int solution(vector<vector<int>> maze) {
    N = maze.size();
    M = maze[0].size();
    board = maze;
    
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < M ; j++)
        {
            if (maze[i][j] == 1)
            {
                sv[1] = {i, j};
                // cv[1] = {i, j};
            }
            else if (maze[i][j] == 2)
            {
                sv[0] = {i, j};
                // cv[0] = {i, j};
            }
            else if (maze[i][j] == 3)
            {
                ev[1] = {i, j};
            }
            else if (maze[i][j] == 4)
            {
                ev[0] = {i, j};
            }
        }
    
    vis[0][sv[0].first][sv[0].second] = true;
    vis[1][sv[1].first][sv[1].second] = true;
    
    int ans = 100;
    dfs(sv[0], sv[1], 0, ans);
    
    return (ans == 100 ? 0 : ans);
}
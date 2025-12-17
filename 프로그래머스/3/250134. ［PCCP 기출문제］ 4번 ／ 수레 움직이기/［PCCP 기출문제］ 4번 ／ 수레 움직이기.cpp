#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

// red : 0, blue : 1
const int INF = 1e9;
const int MX = 4;
int N, M;
vector<vector<int>> maze;
P ev0, ev1;

bool vis0[MX][MX];
bool vis1[MX][MX];

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

void dfs(P cv0, P cv1, int turn, int& mn_turn)
{
    if (turn >= mn_turn)
        return;
    
    if (cv0 == ev0 && cv1 == ev1)
    {
        mn_turn = min(mn_turn, turn);
        return;
    }
    
    auto [cx0, cy0] = cv0;
    auto [cx1, cy1] = cv1;
    
    vector<pair<int, int>> nv0s;
    vector<pair<int, int>> nv1s;
    
    if (cv0 != ev0)
    {
        for (auto [dx, dy] : moves)
        {
            int nx0 = cx0 + dx;
            int ny0 = cy0 + dy;
            
            if (!is_valid(nx0, ny0) || maze[nx0][ny0] == 5 || vis0[nx0][ny0])
                continue;
            
            nv0s.emplace_back(nx0, ny0);
        }
    }
    else
        nv0s.push_back(cv0);
    
    if (cv1 != ev1)
    {
        for (auto [dx, dy] : moves)
        {
            int nx1 = cx1 + dx;
            int ny1 = cy1 + dy;
            
            if (!is_valid(nx1, ny1) || maze[nx1][ny1] == 5 || vis1[nx1][ny1])
                continue;
            
            nv1s.emplace_back(nx1, ny1);
        }
    }
    else
        nv1s.push_back(cv1);
    
    for (const auto& nv0 : nv0s)
    {
        for (const auto& nv1 : nv1s)
        {
            if (nv0 == nv1)
                continue;
            
            if (nv0 == cv1 && nv1 == cv0)
                continue;
            
            auto [nx0, ny0] = nv0;
            auto [nx1, ny1] = nv1;
            
            vis0[nx0][ny0] = true;
            vis1[nx1][ny1] = true;
            
            dfs(nv0, nv1, turn + 1, mn_turn);
            
            vis0[nx0][ny0] = false;
            vis1[nx1][ny1] = false;
        }
    }
    
}

int solution(vector<vector<int>> _maze) 
{
    maze = _maze;
    N = maze.size();
    M = maze[0].size();
    memset(vis0, false, sizeof(vis0));
    memset(vis1, false, sizeof(vis1));
    
    P sv0, sv1;
    
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < M ; j++)
        {
            if (maze[i][j] == 1)
                sv0 = {i, j};
            else if (maze[i][j] == 2)
                sv1 = {i, j};
            else if (maze[i][j] == 3)
                ev0 = {i, j};
            else if (maze[i][j] == 4)
                ev1 = {i, j};
        }
    
    int ans = INF;
    
    auto [sx0, sy0] = sv0;
    auto [sx1, sy1] = sv1;
    
    vis0[sx0][sy0] = true;
    vis1[sx1][sy1] = true;
    dfs(sv0, sv1, 0, ans);

    return ans == INF ? 0 : ans;
}
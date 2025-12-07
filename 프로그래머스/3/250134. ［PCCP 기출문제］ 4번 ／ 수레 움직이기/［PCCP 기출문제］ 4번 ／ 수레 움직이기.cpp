#include <bits/stdc++.h>
using namespace std;

const int MX = 4;
int N, M;

// 0 : blue, 1 : red
pair<int, int> sv[2];
pair<int, int> ev[2];
pair<int, int> cv[2];

vector<vector<int>> board;
int dist[2][MX][MX];

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

void dfs(int color, int& ans)
{
    auto& [cx, cy] = cv[color]; 
    
    if (cv[color] == ev[color] && cv[color ^ 1] != ev[color ^ 1])
    {
        dfs(color ^ 1, ans);
        return;
    }
    
    if (cv[color] == ev[color] && cv[color ^ 1] == ev[color ^ 1])
    {
        // cout << color << ' ' << cx << ' ' << cy << ' ' <<
        //     cv[color ^ 1].first << ' ' << cv[color ^ 1].second << '\n';
        
        // for (int i = 0 ; i < N ; i++)
        // {
        //     for (int j = 0 ; j < M ; j++)
        //     {
        //         cout << dist[color][i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        // for (int i = 0 ; i < N ; i++)
        // {
        //     for (int j = 0 ; j < M ; j++)
        //     {
        //         cout << dist[color ^ 1][i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        // 반대쪽 색깔이 도착하고 미리 도착해있던 여기로 넘어옴
        auto [ex1, ey1] = ev[color];
        auto [ex2, ey2] = ev[color ^ 1]; 
        // ans = min(ans, max(dist[color ^ 1][ex2][ey2], dist[color][ex1][ey1]));
        ans = min(ans, dist[color ^ 1][ex2][ey2]);
        return;
    }
    
    for (auto [dx, dy] : moves)
    {
        int nx = cx + dx;
        int ny = cy + dy;
        int px = cx;
        int py = cy;
        
        if (is_valid(nx, ny) && 
            board[nx][ny] != 5 &&
            dist[color][nx][ny] == -1 && 
            cv[color ^ 1] != make_pair(nx, ny)
           )
        {
            dist[color][nx][ny] = dist[color][cx][cy] + 1;
            cx = nx;
            cy = ny;
            
            dfs(color ^ 1, ans);
            
            dist[color][nx][ny] = -1;
            cx = px;
            cy = py;
        }
    }
}

int solution(vector<vector<int>> maze) {
    N = maze.size();
    M = maze[0].size();
    board = maze;
    memset(dist, -1, sizeof(dist));
    
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < M ; j++)
        {
            if (maze[i][j] == 1)
            {
                sv[1] = {i, j};
                cv[1] = {i, j};
            }
            else if (maze[i][j] == 2)
            {
                sv[0] = {i, j};
                cv[0] = {i, j};
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
    
    dist[0][cv[0].first][cv[0].second] = 0;
    dist[1][cv[1].first][cv[1].second] = 0;
    
    int ans1 = 100;
    int ans2 = 100;
    dfs(0, ans1);
    dfs(1, ans2);
    
    int ans = min(ans1, ans2);
    
    return (ans == 100 ? 0 : ans);
}
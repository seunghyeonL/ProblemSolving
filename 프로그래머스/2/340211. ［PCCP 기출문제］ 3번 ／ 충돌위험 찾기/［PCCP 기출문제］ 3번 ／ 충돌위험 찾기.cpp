#include <bits/stdc++.h>
using namespace std;

int N, X, M;

vector<int> cur_route_idxs;
vector<pair<int, int>> r_pos;
int board[101][101]; // 현재 로봇 위치

int get_danger_cnt()
{
    int ret = 0;
    
    for (int i = 1 ; i <= 100 ; i++)
        for (int j = 1 ; j <= 100 ; j++)
            if (board[i][j] > 1) 
                ret++;
    
    return ret;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    N = points.size();
    X = routes.size();
    M = routes[0].size();
    
    cur_route_idxs.resize(X);
    
    memset(board, 0, sizeof(board));
    
    for (int i = 0 ; i < X ; i++)
    {
        int sn = routes[i][0] - 1;
        int x = points[sn][0];
        int y = points[sn][1];
        r_pos.emplace_back(x, y);
        
        board[x][y] += 1;
    }
    
    int ans = 0;
    int end_cnt = 0;
    
    while (end_cnt < X)
    {
        ans += get_danger_cnt();
        for (int i = 0 ; i < X ; i++)
        {
            int& cri = cur_route_idxs[i];
            if (cri == M - 1) continue;
            
            auto& [cx, cy] = r_pos[i];
            
            int tn = routes[i][cri + 1] - 1;
            int tx = points[tn][0];
            int ty = points[tn][1];
            
            if (cx == tx && cy == ty)
            {
                if (++cri == M - 1)
                {
                    end_cnt++;
                    board[cx][cy]--;
                    continue;
                }
                
                tn = routes[i][cri + 1] - 1;
                tx = points[tn][0];
                ty = points[tn][1];
            }
            
            board[cx][cy]--;
            
            if (cx != tx) 
                cx += (tx - cx) / abs(tx - cx);
            else if (cy != ty)
                cy += (ty - cy) / abs(ty - cy);
            
            board[cx][cy]++;
        }
    }
    
    return ans;
}
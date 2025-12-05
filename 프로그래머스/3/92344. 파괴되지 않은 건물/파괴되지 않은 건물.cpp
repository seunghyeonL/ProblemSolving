#include <bits/stdc++.h>

using namespace std;

const int MX = 1000;
int N, M;
int D[MX + 1][MX + 1];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    N = board.size();
    M = board[0].size();
    
    for (const auto& s_info : skill)
    {
        int t = s_info[0];
        int r1 = s_info[1];
        int c1 = s_info[2];
        int r2 = s_info[3];
        int c2 = s_info[4];
        int w = s_info[5];
        
        w *= (t == 1 ? -1 : 1);
        
        D[r1][c1] += w;
        D[r1][c2 + 1] -= w;
        D[r2 + 1][c1] -= w;
        D[r2 + 1][c2 + 1] += w;
    }
    
    for (int i = 0 ; i < N ; i++)
        for (int j = 1 ; j < M ; j++)
            D[i][j] += D[i][j - 1];
    
    for (int j = 0 ; j < M ; j++)
        for (int i = 1 ; i < N ; i++)
            D[i][j] += D[i - 1][j];
    
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < M ; j++)
            board[i][j] += D[i][j];
    
    int ans = 0;
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < M ; j++)
            if (board[i][j] > 0) 
                ans++;
    
    return ans;
}
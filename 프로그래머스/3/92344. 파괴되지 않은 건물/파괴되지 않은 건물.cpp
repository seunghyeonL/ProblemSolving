#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000;
int N, M;
int D[NMX + 1][NMX + 1];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    memset(D, 0, sizeof(D));
    N = board.size();
    M = board[0].size();
    
    for (auto& sk : skill)
    {
        int t = sk[0];
        int r1 = sk[1];
        int c1 = sk[2];
        int r2 = sk[3];
        int c2 = sk[4];
        int d = sk[5];
            
        int sign = t == 1 ? -1 : 1;
        D[r1][c1] += d * sign;
        D[r1][c2 + 1] -= d * sign;
        D[r2 + 1][c1] -= d * sign;
        D[r2 + 1][c2 + 1] += d * sign;
    }
    
    for (int i = 0 ; i < N ; i++)
    {
        inclusive_scan(D[i], D[i] + M, D[i]);
    }
    
    for (int j = 0 ; j < M ; j++)
    {
        for (int i = 1 ; i < N ; i++)
            D[i][j] += D[i - 1][j];
    }
    
    int ans = 0;
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < M ; j++)
            if (board[i][j] + D[i][j] > 0)
                ans++;
    

    return ans;
}
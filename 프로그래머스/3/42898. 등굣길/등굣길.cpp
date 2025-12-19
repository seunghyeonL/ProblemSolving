#include <bits/stdc++.h>
using namespace std;

// 오른쪽 또는 아래쪽으로만 이동

const int MOD = 1'000'000'007;
const int NMX = 100;
int N, M;

// 1 : 웅덩이
int board[NMX + 1][NMX + 1];
// (0, 0) -> (x, y) 최단경로 개수
int dp[NMX + 1][NMX + 1];

int solution(int m, int n, vector<vector<int>> puddles) 
{
    N = m;
    M = n;
    
    memset(dp, 0, sizeof(dp));
    memset(board, 0, sizeof(board));
    
    for (const auto& pud : puddles)
    {
        int x = pud[0];
        int y = pud[1];
        
        board[x][y] = 1;
    }
    
    dp[1][1] = 1;
    
    for (int i = 1 ; i <= N ; i++)
        for (int j = 1 ; j <= M ; j++)
        {
            if (board[i][j])
                continue;
            
            if (i < N) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            if (j < M) dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
        }
    
    return dp[N][M];
}
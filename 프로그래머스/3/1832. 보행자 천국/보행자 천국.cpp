#include <bits/stdc++.h>
using namespace std;

// x, y, 들어오는방향 을 상태로 dp

const int MOD = 20170805;
const int NMX = 500;

int N, M;
vector<vector<int>> board;

// 0 : 아래로, 1 : 오른쪽으로
int dp[NMX][NMX][2];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> _city_map) 
{
    N = m;
    M = n;
    board = _city_map;
    memset(dp, 0, sizeof(dp));
    
    dp[0][1][1] = 1;
    dp[1][0][0] = 1;
    
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < M ; j++)
        {
            if (i == 0 && j == 0) continue;
            if (board[i][j] == 1) continue;
            
            // 아래로 이동
            if (i < N - 1) 
            {
                if (board[i][j] == 0)
                    dp[i + 1][j][0] += dp[i][j][0] + dp[i][j][1];
                else
                    dp[i + 1][j][0] += dp[i][j][0];

                
                dp[i + 1][j][0] %= MOD;
            }
            
            // 오른쪽으로 이동
            if (j < M - 1)
            {
                if (board[i][j] == 0)
                    dp[i][j + 1][1] += dp[i][j][0] + dp[i][j][1];
                else
                    dp[i][j + 1][1] += dp[i][j][1];

                
                dp[i][j + 1][1] %= MOD;
            }
        }
    
    return (dp[N - 1][M - 1][0] + dp[N - 1][M - 1][1]) % MOD;
}
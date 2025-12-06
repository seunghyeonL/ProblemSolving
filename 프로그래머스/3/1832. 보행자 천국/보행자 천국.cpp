#include <bits/stdc++.h>
using namespace std;

const int MOD = 20170805;
const int MX = 500;
// dp[i][j][dir] : {i, j} 위치에 dir 방향으로 들어오는 경로 개수
// dir ->  0 : 오른쪽, 1 : 아래쪽
int dp[MX + 1][MX + 1][2];

int N, M;

bool is_valid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

vector<pair<int, int>> moves
{
    {0, 1},
    {1, 0},
};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) 
{    
    N = m;
    M = n;
    
    memset(dp, 0, sizeof(dp));
    
    dp[0][1][0] = 1;
    dp[1][0][1] = 1;
    
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < M ; j++)
        {
            if (i == 0 && j == 0) continue;
            
            if (city_map[i][j] == 0)
            {
                dp[i + 1][j][1] = dp[i][j + 1][0] = (dp[i][j][0] + dp[i][j][1]) % MOD;
            }
            else if (city_map[i][j] == 2)
            {
                dp[i + 1][j][1] = dp[i][j][1];
                dp[i][j + 1][0] = dp[i][j][0];
            }
        }
    
    return (dp[N - 1][M - 1][0] + dp[N - 1][M - 1][1]) % MOD;
}
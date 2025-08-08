#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int N = land.size();
    
    vector<vector<int>> dp(N, vector<int>(4, 0)); // dp[i][j] : (i, j)를 마지막으로 밟을 때의 최대값
    
    for (int i = 0 ; i < 4 ; i++)
    {
        dp[0][i] = land[0][i];
    }
    
    for (int i = 1 ; i < N ; i++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
            for (int k = 0 ; k < 4 ; k++)
            {
                if (k == j) continue;
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + land[i][j]);
            }
        }
    }

    return *max_element(dp.back().begin(), dp.back().end());
}
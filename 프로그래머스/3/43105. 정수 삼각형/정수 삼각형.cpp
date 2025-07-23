#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    int size = triangle.size();

    vector<vector<int>> dp(size, vector<int>(size, 0));

    dp[0][0] = triangle[0][0];
    dp[1][0] = triangle[1][0] + triangle[0][0];
    dp[1][1] = triangle[1][1] + triangle[0][0];

    for (int i = 2; i < size; i++)
    {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];

        for (int j = 1; j <= i; j++)
        {
            int l = dp[i - 1][j - 1];
            int r = dp[i - 1][j];
            int cur = triangle[i][j];

            dp[i][j] = max(l + cur, r + cur);
        }
    }
    
    return *max_element(dp[size - 1].begin(), dp[size - 1].end());
}
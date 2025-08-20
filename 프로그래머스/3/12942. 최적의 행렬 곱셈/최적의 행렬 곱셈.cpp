#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> matrix_sizes) {
    int N = matrix_sizes.size();
    const int INF = 1e9;
    
    vector<vector<int>> dp(N, vector<int>(N, INF));
    
    for (int i = 0 ; i < N ; i++)
    {
        dp[i][i] = 0;
    }
    
    for (int i = 0 ; i < N ; i++)
    {
        dp[i][i] = 0;
    }
    
    for (int i = 0 ; i < N - 1 ; i++)
    {
        int a = matrix_sizes[i][0];
        int b = matrix_sizes[i][1];
        int c = matrix_sizes[i + 1][1];
        
        dp[i][i + 1] = a * b * c;
    }
    
    for (int len = 2 ; len < N ; len++)
    {
        for (int i = 0 ; i < N - len ; i++)
        {
            int j = i + len;
            for (int k = i ; k < j ; k++)
            {
                int a = matrix_sizes[i][0];
                int b = matrix_sizes[k][1];
                int c = matrix_sizes[j][1];
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a * b * c);   
            }
        }
    }
    
    return dp[0][N - 1];
}
#include <string>
#include <vector>
#include <functional>

using namespace std;

int solution(int n, vector<int> tops)
{
    int answer = 0;

    // dp[idx][0] : idx 변 오른쪽 하단이 마름모가 아닌 경우의 수
    // dp[idx][1] : idx 변 오른쪽 하단이 마름모인 경우의 수
    vector<vector<int>> dp(n, vector<int>(2));

    dp[0][1] = 1; // 오른쪽 하단 마름모
    dp[0][0] = 2; // 나머지 경우
    if (tops[0])
        dp[0][0]++; // 윗변 마름모

    for (int i = 1; i < n; i++)
    {
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1]; // 오른쪽 하단 마름모

        // 마름모를 안쓰는 경우
        dp[i][0] += dp[i - 1][0] + dp[i - 1][1]; 
        
        // 윗변 마름모
        if (tops[i])
            dp[i][0] += dp[i - 1][0] + dp[i - 1][1]; 
        
        // 왼쪽 하단 마름모
        dp[i][0] += dp[i - 1][0];                    

        dp[i][0] %= 10007;
        dp[i][1] %= 10007;
    }

    return (dp[n - 1][0] + dp[n - 1][1]) % 10007;
}


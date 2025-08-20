#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>

using namespace std;

int solution(int n, vector<int> money)
{
    const int MOD = 1000000007;

    sort(money.begin(), money.end());
    vector<int> dp(n + 1, 0); // dp[i] : i원을 만드는 경우의 수
    dp[0] = 1;

    for (int m : money)
    {
        for (int i = m; i <= n; i++)
        {
            dp[i] += dp[i - m];

            if (dp[i] >= MOD)
                dp[i] -= MOD;
        }
    }

    return dp[n];
}

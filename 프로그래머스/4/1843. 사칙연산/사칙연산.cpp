#include <vector>

#include <string>
using namespace std;

int solution(vector<string> arr)
{
    using P = pair<int, int>;
    int answer = -1;
    int size = arr.size();
    // 숫자 총 개수
    int n = size / 2 + 1;
    
    // vector<vector<P>> dp(n, vector<P>(n));

    // dp[i][j] : i번째 숫자에서 j번째 숫자 까지 연산을 수행할때 최솟값/최댓값
    vector<vector<int>> minDp(n, vector<int>(n));
    vector<vector<int>> maxDp(n, vector<int>(n));

    // len : 숫자개수
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            if (len == 1)
            {
                int value = stoi(arr[i * 2]);
                minDp[i][i] = value;
                maxDp[i][i] = value;
                continue;
            }

            int minValue = 1e9;
            int maxValue = -1e9;

            int j = i + len - 1;

            for (int k = i; k < j; k++)
            {
                if (arr[2 * k + 1] == "+")
                {
                    minValue = min(minValue, minDp[i][k] + minDp[k + 1][j]);
                    maxValue = max(maxValue, maxDp[i][k] + maxDp[k + 1][j]);
                }
                else
                {
                    minValue = min(minValue, minDp[i][k] - maxDp[k + 1][j]);
                    maxValue = max(maxValue, maxDp[i][k] - minDp[k + 1][j]);
                }
            }

            minDp[i][j] = minValue;
            maxDp[i][j] = maxValue;
        }
    }

    return maxDp[0][n - 1];
}
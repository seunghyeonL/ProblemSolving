#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number)
{
    if (N == number)
        return 1;

    int cnt = 0;

    // dp[n] : N을 n번 써서 만들 수 있는 모든 수 집합
    vector<unordered_set<int>> dp(9);

    auto makeNumOnlyN = [&](int length)
    {
        int result = 0;
        for (int i = 0, place = 1; i < length; i++, place *= 10)
        {
            result += N * place;
        }

        return result;
    };

    for (int i = 1; i <= 8; i++)
    {
        int numOnlyN = makeNumOnlyN(i);
        
        if (number == numOnlyN) return i;
            
        dp[i].insert(numOnlyN);
    }

    for (int i = 2; i <= 8; i++)
    {
        for (int j = 1; j < i; j++)
        {
            for (int l : dp[j])
            {
                for (int r : dp[i - j])
                {
                    // +
                    if (l + r == number)
                    {
                        return i;
                    }

                    if (l + r != 0)
                    {
                        dp[i].insert(l + r);
                    }

                    // -
                    if (l - r == number)
                    {
                        return i;
                    }

                    if (l - r != 0)
                    {
                        dp[i].insert(l - r);
                    }

                    // *
                    if (l * r == number)
                    {
                        return i;
                    }

                    dp[i].insert(l * r);

                    // /

                    if (l / r == number)
                    {
                        return i;
                    }

                    if (l / r != 0)
                    {
                        dp[i].insert(l / r);
                    }
                }
            }
        }
    }

    return -1;
}

#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isPrime(long long n)
{
    if (n == 1)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }
    if (n % 2 == 0)
    {
        return false;
    }
    for (long long i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(int n, int k)
{
    int answer{};
    long long buffer{};

    for (int i = 0; n > 0; i++)
    {
        int cur = n % k;
        n /= k;

        if (cur == 0)
        {
            if (isPrime(buffer))
            {
                answer++;
            }
            buffer = 0;
            i = -1;
        }
        else
        {
            long long diff = cur;
            for (int j = 0; j < i; j++)
            {
                diff *= 10;
            }
            buffer += diff;
        }
    }

    if (buffer > 0)
    {
        if (isPrime(buffer))
        {
            answer++;
        }
    }

    return answer;
}

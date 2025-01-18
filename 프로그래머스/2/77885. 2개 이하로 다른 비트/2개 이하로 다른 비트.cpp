#include <string>
#include <vector>

using namespace std;

long long f(long long n)
{
    long long answer = 0;
    vector<long long> rbn;
    while (n > 0)
    {
        rbn.push_back(n % 2);
        n /= 2;
    }

    long long idx = 0;
    bool findZero = false;
    for (; idx < rbn.size(); idx++)
    {
        if (rbn[idx] == 0)
        {
            rbn[idx] = 1;
            findZero = true;
            break;
        }
    }

    if (!findZero)
        rbn.push_back(1);

    for (idx -= 1; idx >= 0; idx--)
    {
        if (rbn[idx] == 1)
        {
            rbn[idx] = 0;
            break;
        }
    }

    for (long long i = 0; i < rbn.size(); i++)
    {
        long long cnt = i;
        long long weight = 1;
        while (cnt > 0)
        {
            weight *= 2;
            --cnt;
        }
        answer += rbn[i] * weight;
    }

    return answer;
}

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;

    for (long long number : numbers)
    {
        answer.push_back(f(number));
    }

    return answer;
}
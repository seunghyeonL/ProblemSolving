#include <string>
#include <vector>

using namespace std;

long long f(long long n)
{
    long long mask = 1;

    while (true)
    {
        if ((n & mask) == 0)
        {
            n |= mask;
            break;
        }
        // cout << mask << '\n';
        mask <<= 1;
    }

    mask >>= 1;

    while (mask > 0)
    {
        if ((n & mask) != 0)
        {
            n &= ~mask;
            break;
        }
        // cout << mask << '\n';
        mask >>= 1;
    }

    return n;
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

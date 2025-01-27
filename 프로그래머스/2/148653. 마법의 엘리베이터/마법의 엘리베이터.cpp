#include <string>
#include <vector>

using namespace std;

bool check(int n)
{
    if (n == 5)
    {
        return false;
    }
    
    while (n > 0)
    {
        if (n % 10 > 5)
        {
            return true;
        }

        if (n % 10 < 5)
        {
            return false;
        }

        n /= 10;
    }

    return true;
}

int solution(int storey)
{
    int answer = 0;

    while (storey > 0)
    {
        int curDigit = storey % 10;

        if (check(storey))
        {
            answer += (10 - curDigit);
            storey += 10;
        }
        else
        {
            answer += curDigit;
        }

        storey /= 10;
    }

    return answer;
}
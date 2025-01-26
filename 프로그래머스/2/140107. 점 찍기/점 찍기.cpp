#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d)
{
    long long answer = 0;

    for (long long i = 0; k * i <= d; i++)
    {
        long long begin = 0;
        long long end = d / k;

        long long jMax = sqrt((long long)d * d - i * i * k * k) / k;

        answer += jMax + 1;
    }
    return answer;
}
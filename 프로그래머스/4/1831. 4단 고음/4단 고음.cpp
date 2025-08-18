#include <vector>
#include <string>
#include <functional>
#include <cmath>

using namespace std;

long long lbound(long long n)
{
    // l[n] = 1 * 3^n + 2*n
    return pow(3, n) + 2 * n;
}

long long rbound(long long n)
{
    /*
    r[0] = 1
    r[n + 1] = 3 * r[n] + 2
    r[n + 1] + 1 = 3 * (r[n] + 1)
    r[n] + 1 = (r[0] + 1) * 3^n
    r[n] = 2 * 3^n - 1
    */
    return 2 * pow(3, n) - 1;
}

int solution(int n)
{
    int answer = 0;

    long long ln = n;

    int tripleNum = 0;
    for (int i = 0; i < 30; i++)
    {
        if (lbound(i) <= ln && rbound(i) >= ln)
        {
            tripleNum = i;
            break;
        }
    }

    if (tripleNum == 0)
        return 0;

    if (tripleNum == 1)
        return 1;

    // 현재 값, 사용 가능한 +개수, 사용 가능한 *개수
    function<void(int, int, int)> dfs = [&](int x, int p, int r)
    {
        if (2 * r < p)
            return;

        if (r == 0)
        {
            if (x == 1 && p == 0)
                answer++;
            return;
        }

        if (r > 0 && x % 3 == 0)
        {
            dfs(x / 3, p, r - 1);
        }

        if (p > 0)
        {
            dfs(x - 1, p - 1, r);
        }
    };

    dfs(n, 2 * tripleNum, tripleNum);

    return answer;
}
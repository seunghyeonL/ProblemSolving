#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long solution(int n, vector<int> works)
{
    using ll = long long;
    ll answer = 0;

    if (n >= accumulate(works.begin(), works.end(), 0))
    {
        return 0;
    }

    sort(works.begin(), works.end(), greater<int>());

    /*
    N 으로 works의 최댓값을 얼마나 줄일 수 있는가
    N으로 가능한 works[i]가 최댓값이 되는 최대 i 찾기
    이분탐색
    */

    auto check = [&](int idx)
    {
        ll need = 0;
        for (int i = 0; i < idx; i++)
        {
            need += works[i] - works[idx];
        }
        return need <= n;
    };

    int left = 0;
    int right = works.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (check(mid))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    int tidx = right;

    int need = 0;
    for (int i = 0; i < tidx; i++)
    {
        need += works[i] - works[tidx];
        works[i] = works[tidx];
    }

    int remain = n - need;

    while (remain > 0)
    {
        for (int i = 0; i <= tidx; i++)
        {
            if (remain > 0)
            {
                works[i]--;
                remain--;
            }
        }
    }

    for (int work : works)
    {
        answer += work * work;
    }

    return answer;
}

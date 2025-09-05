#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int solution(string name)
{
    int answer = 0;
    int size = name.size();

    /*
        세로이동은 각 문자c 에 대해 c - 'A', 'Z' - c 중 작은 만큼 필요
        가로이동은 A가 아닌 문자들에 대하여 A가 아닌 문자 사이 구간을 구하고
        (2 * cpl + (size - i + 1) < size || cpl + 2 * (size - i + 1) < size 이
       조건을 만족하는 구간이어야 함)
        가장 긴 구간을 회피하는 방향으로 이동 0 1
       2 3 4 5 6 A B A A A C A mpl - 0, size - mpr 대소비교하기 전자가 작을때는
       mpl을 만날때까지 오른쪽으로 이동 후자가 작을때는 mpr을 만날까지 왼쪽으로
       이동 이후 방향 전환
    */

    // 세로이동
    auto getCharCost = [&](int idx)
    {
        char c = name[idx];
        answer += min(c - 'A', 'Z' - c + 1);
    };

    for (int i = 0; i < size; i++)
    {
        getCharCost(i);
    }

    int mp = size - 1;
    int mpl = 0;
    int mpr = 0;
    int cpl = 0;

    for (int i = 0; i < size; i++)
    {
        if (name[i] == 'A')
        {
            continue;
        }

        int cp = min(2 * cpl + size - i, cpl + 2 * (size - i));

        if (cp < mp)
        {
            // cout << "p: " << mp << ' ' << cp << '\n';
            mp = cp;
            mpl = cpl;
            mpr = i;
        }

        cpl = i;

        // cout << mpl << ' ' << mpr << '\n';
    }

    if (cpl < mp)
    {
        // cout << "p: " << mp << ' ' << cp << '\n';
        mp = cpl;
        mpl = cpl;
        mpr = 0;

        // cout << mpl << ' ' << mpr << '\n';
    }

    return answer + mp;
}

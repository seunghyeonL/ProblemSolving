#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(long long n, vector<string> bans)
{
    using ll = long long;
    /*
        str -> num
        a~z를 1~26으로 생각
        a : 1
        z : 26
        aa : 26 * 1 + 1
        az : 26 * 1 + 26
        ba : 26 * 2 + 1
        za : 26 * (25 + 1) + 0
        zz : 26 * (26)  + 26
        aaa : 26 * 26 * 1 + 26 * 1 + 1

        num -> str
        bijective 보정 - 1을 빼주고 a~z를 0~25로 생각
    */


    auto strToNum = [&](const string &s) -> ll
    {
        ll res = 0;
        for (char c : s)
        {
            int v = (c - 'a' + 1); // a=1..z=26
            res = res * 26 + v;
        }
        return res;
    };

    auto numToStr = [&](ll x) -> string
    {
        string t;
        while (x > 0)
        {
            x--; // bijective 보정
            int d = x % 26;
            t.push_back(char('a' + d));
            x /= 26;
        }
        reverse(t.begin(), t.end());
        return t;
    };

    // bans → 숫자로 변환
    vector<ll> banNums;
    banNums.reserve(bans.size());
    for (auto &s : bans)
        banNums.push_back(strToNum(s));

    // 정렬 + 중복 제거
    sort(banNums.begin(), banNums.end());

    for (ll b : banNums)
    {
        if (b <= n)
            ++n;
        else
            break;
    }

    return numToStr(n);
}

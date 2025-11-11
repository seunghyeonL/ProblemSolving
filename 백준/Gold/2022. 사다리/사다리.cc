#include <bits/stdc++.h>
using namespace std;

long double x, y, c;
long long llx, lly, llc;

long long root(__int128 n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    __int128 l = 1, r = n;

    while (l <= r)
    {
        __int128 m = (l + r) / 2;

        if (m <= n / m)
            l = m + 1;
        else
            r = m - 1;
    }

    return r;
}

// 건물 사이 거리가 dist 일때 C가 주어진 c이상인가
bool check(long long dist)
{
    long long A = root((__int128)llx * llx - (__int128)dist * dist);
    long long B = root((__int128)lly * lly - (__int128)dist * dist);

    long long C = (__int128)A * B / (A + B);

    // cout << C << ' ' << dist << '\n';

    if (C <= llc)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
    3000000000 3000000000 100
     */

    cin >> x >> y >> c;

    llx = round(x * 10000);
    lly = round(y * 10000);
    llc = round(c * 10000);

    long long r = min(llx, lly);
    long long l = 0;

    while (l <= r)
    {
        long long m = (l + r) / 2;

        if (check(m))
            r = m - 1;
        else
            l = m + 1;
    }

    long double ans = l;
    ans /= 10000;

    cout << fixed;
    cout.precision(3);
    cout << ans;

    // inputFileStream.close();
    return 0;
}
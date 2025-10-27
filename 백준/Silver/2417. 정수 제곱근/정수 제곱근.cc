#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll N;

ll power(ll n, ll p)
{
    ll ret = 1;
    while (p-- > 0)
    {
        ret *= n;
    }
    return ret;
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
     */

    cin >> N;
    ll l = 0, r = power(2, 32) - 1;

    if (N == 0)
    {
        cout << 0;
        return 0;
    }

    while (l <= r)
    {
        ll m = (l + r) / 2;

        if (m >= ceil((double)N / m))
            r = m - 1;
        else
            l = m + 1;
    }

    cout << l;
    // inputFileStream.close();
    return 0;
}
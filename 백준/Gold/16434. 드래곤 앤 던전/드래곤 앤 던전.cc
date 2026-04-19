#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1LL << 62;
const int NMX = 123456;
int N;
ll sa, ca, mh, ch;
tuple<int, ll, ll> room[NMX];

bool fight(ll e_a, ll e_h)
{
    if ((ch - 1) / e_a >= (e_h - 1) / ca)
    {
        ch -= (e_h - 1) / ca * e_a;
        return true;
    }
    else
        return false;
}

void recover(ll ra, ll rh)
{
    ca += ra;
    ch = min(ch + rh, mh);
}

bool check(ll m)
{
    mh = m;
    ch = mh;
    ca = sa;

    for (int i = 0; i < N; i++)
    {
        auto [t, a, h] = room[i];

        if (t == 1)
        {
            if (!fight(a, h))
                return false;

            // cout << mh << ' ' << ch << '\n';
        }
        else
        {
            recover(a, h);
            // cout << mh << ' ' << ch << '\n';
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> sa;
    for (int i = 0; i < N; i++)
    {
        int t, a, h;
        cin >> t >> a >> h;
        room[i] = {t, a, h};
    }

    ll l = 1, r = INF;
    while (l <= r)
    {
        ll m = (l + r) / 2;

        if (check(m))
            r = m - 1;
        else
            l = m + 1;
    }

    cout << l;

    // inputFileStream.close();
    return 0;
}
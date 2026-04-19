#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int NMX = 1000000;

int spf[NMX + 1];

void solve()
{
    int N;
    cin >> N;

    map<int, int> um;

    while (spf[N] > 0)
    {
        int p = spf[N];
        N /= p;
        um[p]++;
    }

    for (auto [p, cnt] : um)
    {
        cout << p << ' ' << cnt << '\n';
    }
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
        spf
    */

    for (int i = 2; i <= NMX; i++)
    {
        if (spf[i] > 0)
            continue;
        spf[i] = i;

        for (ll j = (ll)i * i; j <= NMX; j += i)
        {
            spf[j] = i;
        }
    }

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
        solve();

    // inputFileStream.close();
    return 0;
}
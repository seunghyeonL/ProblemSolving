#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        비트마스킹
    */

    int N, M;
    cin >> N >> M;

    vector<long long> smasks(N);
    for (int i = 0; i < N; i++)
    {
        string gname, bits;
        cin >> gname >> bits;

        for (char c : bits)
        {
            smasks[i] <<= 1;
            if (c == 'Y')
                smasks[i]++;
        }
    }

    long long tmask = 0;
    for (int i = 0; i < N; i++)
    {
        tmask |= smasks[i];
    }

    if (tmask == 0)
    {
        cout << -1 << '\n';
        return 0;
    }

    int res = N + 1;
    for (int gmask = 0; gmask < (1 << N); gmask++)
    {
        long long sunion = 0;
        int gcnt = 0;
        for (int i = 0; i < N; i++)
        {
            long long smask = smasks[i];
            if (gmask >> i & 1)
            {
                sunion |= smask;
                gcnt++;
            }
        }

        if (sunion == tmask)
        {
            res = min(res, gcnt);
        }
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int NMX = 1000000;
int N, M, K;
ll arr[NMX + 1];
ll FT[NMX + 1];

ll find_sum(ll i)
{
    ll ret = 0;
    while (i > 0)
    {
        ret += FT[i];
        i -= (i & -i);
    }
    return ret;
}

void update(ll i, ll diff)
{
    while (i <= N)
    {
        FT[i] += diff;
        i += (i & -i);
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
     */

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++)
    {
        update(i, arr[i]);
    }

    for (int i = 0; i < M + K; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1)
        {
            ll diff = c - arr[b];
            arr[b] = c;
            update(b, diff);
        }
        else
        {
            cout << find_sum(c) - find_sum(b - 1) << '\n';
        }
    }

    // inputFileStream.close();
    return 0;
}
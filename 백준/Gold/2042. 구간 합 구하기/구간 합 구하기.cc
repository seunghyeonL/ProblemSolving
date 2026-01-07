#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int NMX = 1000000;
int N, M, K;

ll arr[NMX + 1];
ll FT[NMX + 1];

void init_FT()
{
    for (int i = 1; i <= N; i++)
        FT[i] = arr[i];

    for (int i = 1; i <= N; i++)
    {
        int pi = i + (i & -i);
        if (pi <= N)
            FT[pi] += FT[i];
    }
}

ll get_prefix_sum(int i)
{
    ll ret = 0;
    while (i > 0)
    {
        ret += FT[i];
        i -= (i & -i);
    }
    return ret;
}

ll get_range_sum(int l, int r)
{
    return get_prefix_sum(r) - get_prefix_sum(l - 1);
}

void update(int i, ll diff)
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

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    init_FT();

    for (int i = 0; i < M + K; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1)
        {
            update(b, c - arr[b]);
            arr[b] = c;
        }
        else
        {
            cout << get_range_sum(b, c) << '\n';
        }
    }

    // inputFileStream.close();
    return 0;
}
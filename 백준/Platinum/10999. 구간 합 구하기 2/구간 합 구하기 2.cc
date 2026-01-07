#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int NMX = 1000000;
int N, M, K;

ll arr[NMX + 1];
ll D[NMX + 1];
ll BIT1[NMX + 1]; // 1차항 계수
ll BIT2[NMX + 1]; // 상수항

void init_BIT()
{
    for (int i = 1; i <= N; i++)
    {
        BIT1[i] = D[i];
        BIT2[i] = -D[i] * (i - 1);
    }

    for (int i = 1; i <= N; i++)
    {
        int pi = i + (i & -i);
        if (pi <= N)
        {
            BIT1[pi] += BIT1[i];
            BIT2[pi] += BIT2[i];
        }
    }
}

void update_BIT(int i, ll diff, ll *BIT)
{
    while (i <= N)
    {
        BIT[i] += diff;
        i += (i & -i);
    }
}

void update_range(int l, int r, ll diff)
{
    update_BIT(l, diff, BIT1);
    if (r + 1 <= N)
        update_BIT(r + 1, -diff, BIT1);

    update_BIT(l, -diff * (l - 1), BIT2);
    if (r + 1 <= N)
        update_BIT(r + 1, diff * r, BIT2);
}

ll get_sum_BIT(int i, ll *BIT)
{
    ll ret = 0;
    while (i > 0)
    {
        ret += BIT[i];
        i -= (i & -i);
    }
    return ret;
}

ll get_sum(int i)
{
    return get_sum_BIT(i, BIT1) * i + get_sum_BIT(i, BIT2);
}

ll get_range_sum(int l, int r)
{
    return get_sum(r) - get_sum(l - 1);
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

    D[1] = arr[1];
    for (int i = 2; i <= N; i++)
        D[i] = arr[i] - arr[i - 1];

    init_BIT();

    for (int i = 0; i < M + K; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1)
        {
            ll d;
            cin >> d;

            update_range(b, c, d);
        }
        else
            cout << get_range_sum(b, c) << '\n';
    }

    // inputFileStream.close();
    return 0;
}

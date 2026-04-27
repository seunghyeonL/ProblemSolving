#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int NMX = 1000000;
int N, M, K;
ll arr[NMX + 1];
ll ST[4 * NMX];

ll initST(int cv, int s, int e)
{
    if (s == e)
        return ST[cv] = arr[s];

    int m = (s + e) / 2;

    return ST[cv] = initST(cv * 2, s, m) + initST(cv * 2 + 1, m + 1, e);
}

void update(int cv, int s, int e, int idx, ll dif)
{
    if (e < idx || idx < s)
        return;

    ST[cv] += dif;

    if (s == e)
        return;

    int m = (s + e) / 2;

    update(cv * 2, s, m, idx, dif);
    update(cv * 2 + 1, m + 1, e, idx, dif);
}

ll findSum(int cv, int s, int e, int l, int r)
{
    if (e < l || r < s)
        return 0;

    if (l <= s && e <= r)
        return ST[cv];

    int m = (s + e) / 2;
    return findSum(2 * cv, s, m, l, r) + findSum(2 * cv + 1, m + 1, e, l, r);
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

    initST(1, 1, N);

    for (int i = 0; i < M + K; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1)
        {
            ll dif = c - arr[b];
            arr[b] = c;
            update(1, 1, N, b, dif);
        }
        else
        {
            cout << findSum(1, 1, N, b, c) << '\n';
        }
    }

    // inputFileStream.close();
    return 0;
}
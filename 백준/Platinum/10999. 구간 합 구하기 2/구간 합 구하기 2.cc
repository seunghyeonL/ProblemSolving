#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int NMX = 1000000;
int N, M, K;
ll arr[NMX + 1];
__int128 ST[4 * NMX];
__int128 lazy[4 * NMX];

__int128 initST(int cv, int s, int e)
{
    if (s == e)
        return ST[cv] = arr[s];

    int m = (s + e) / 2;

    return ST[cv] = initST(cv * 2, s, m) + initST(cv * 2 + 1, m + 1, e);
}

void printbint(__int128 n)
{
    vector<int> v;
    bool isNeg = n < 0;
    if (isNeg)
        n = -n;

    while (n > 0)
    {
        v.push_back(n % 10);
        n /= 10;
    }

    reverse(v.begin(), v.end());

    if (isNeg)
        cout << '-';

    for (int el : v)
    {
        cout << el;
    }
    cout << '\n';
}

void updateLazy(int cv, int s, int e)
{
    if (lazy[cv] != 0)
    {
        ST[cv] += (e - s + 1) * lazy[cv];

        if (s != e) // leaf가 아닐때
        {
            lazy[2 * cv] += lazy[cv];
            lazy[2 * cv + 1] += lazy[cv];
        }

        lazy[cv] = 0;
    }
}

void updateRange(int cv, int s, int e, int l, int r, __int128 dif)
{
    updateLazy(cv, s, e);

    if (e < l || r < s)
        return;

    if (l <= s && e <= r)
    {
        ST[cv] += (e - s + 1) * dif;

        if (s != e)
        {
            lazy[2 * cv] += dif;
            lazy[2 * cv + 1] += dif;
        }
        return;
    }

    int m = (s + e) / 2;

    updateRange(cv * 2, s, m, l, r, dif);
    updateRange(cv * 2 + 1, m + 1, e, l, r, dif);
    ST[cv] = ST[2 * cv] + ST[2 * cv + 1];
}

__int128 findSum(int cv, int s, int e, int l, int r)
{
    updateLazy(cv, s, e);
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
        int a;
        cin >> a;

        if (a == 1)
        {
            int b, c;
            ll d;
            cin >> b >> c >> d;

            updateRange(1, 1, N, b, c, d);
        }
        else
        {
            int b, c;
            cin >> b >> c;
            printbint(findSum(1, 1, N, b, c));
        }
    }

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 1;
const int NMX = 100000;
int N, M;
int arr[NMX + 1];
int ST[4 * NMX];

int initST(int cv, int s, int e)
{
    if (s == e)
        return ST[cv] = arr[s];

    int m = (s + e) / 2;

    return ST[cv] = min(initST(cv * 2, s, m), initST(cv * 2 + 1, m + 1, e));
}

int findMin(int cv, int s, int e, int l, int r)
{
    if (e < l || r < s)
        return INF;

    if (l <= s && e <= r)
        return ST[cv];

    int m = (s + e) / 2;
    return min(findMin(2 * cv, s, m, l, r), findMin(2 * cv + 1, m + 1, e, l, r));
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

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    initST(1, 1, N);

    for (int i = 0; i < M; i++)
    {
        int l, r;
        cin >> l >> r;

        cout << findMin(1, 1, N, l, r) << '\n';
    }

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int NMX = 1000000;
int N;
ll K;
int A[NMX];

// A[i] 에서 A[i + 1] 사이에 얻을 수 있는 현금
__int128 money(int i, __int128 x)
{
    if (i == N - 1)
        return x * (x + 1) / 2;

    __int128 gap = A[i + 1] - A[i];
    __int128 d = x < gap ? x : gap;

    return x * d - d * (d - 1) / 2;
}

// x로 증가시킬때 K원 이상 얻을 수 있는지 여부
bool check(ll x)
{
    __int128 sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += money(i, x);
        if (sum >= K)
            return true;
    }

    return false;
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
        X를 증가시킬수록 얻을 수 있는 현금 양 증가
     */

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(A, A + N);

    ll l = 1, r = 1e18;
    while (l <= r)
    {
        __int128 m = (l + r) / 2;

        if (check(m))
            r = m - 1;
        else
            l = m + 1;
    }

    cout << l;

    // inputFileStream.close();
    return 0;
}
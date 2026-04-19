#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int NMX = 100000;
int N, K;
int arr[NMX + 1];

bool check(ll n)
{
    ll cnt = 0;

    for (int j = 1; j <= N; j++)
    {
        cnt += partition_point(arr, arr + N, [j, n](int el)
                               { return (ll)el * j < n; }) -
               arr;
    }

    return cnt - K >= 0;
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
        어떤 수 n을 잡을때 n 보다 작은 수 개수가 k - 1개 이면
        B[k] = n
    */

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        arr[i] = i + 1;

    ll l = 0, r = K;
    while (l <= r)
    {
        ll m = (l + r) / 2;

        if (check(m))
            r = m - 1;
        else
            l = m + 1;
    }

    cout << r;

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll getPrimeNum(ll n, ll p)
{
    ll res = 0;
    ll div = p;
    while (n / div > 0)
    {
        res += n / div;
        div *= p;
    }

    return res;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        n!에서 소수 p의 개수
        = sum n/p + n/p^2 + ...
    */

    // ifstream inputFileStream("input.txt");

    ll n, m;
    cin >> n >> m;

    ll two = getPrimeNum(n, 2) - getPrimeNum(m, 2) - getPrimeNum(n - m, 2);
    ll five = getPrimeNum(n, 5) - getPrimeNum(m, 5) - getPrimeNum(n - m, 5);

    cout << min(two, five);
    // inputFileStream.close();
    return 0;
}
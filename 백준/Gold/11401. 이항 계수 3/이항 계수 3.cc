#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        페르마의 소정리
        inverse(N) = N^(M-2) mod M

        N! = N (N - 1)!
        inverse (N - 1)! * inverse N = inverse(N!) mod M
        inverse (N - 1)! = inverse(N!) * N mod M

        NCK = N! / (K! * (N - K)!)
        NCK = N! * inverse(K!) * inverse((N - K!)) mod M
    */

    using ll = long long;
    int N, K;
    cin >> N >> K;
    
    if (K == 0 || K == N)
    {
        cout << 1 << '\n';
        return 0;
    }

    int MOD = 1000000007;

    auto fastModPower = [&](ll a, ll p) -> ll
    {
        ll res = 1;

        while (p > 0)
        {
            if (p % 2 == 1)
            {
                res *= a;
                res %= MOD;
                p--;
            }

            if (p == 0)
                break;

            a = a * a % MOD;
            p /= 2;
        }

        return res;
    };

    vector<ll> factorials(N + 1);
    factorials[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        factorials[i] = factorials[i - 1] * i % MOD;
    }

    vector<ll> iFactorials(N + 1);

    iFactorials[N] = fastModPower(factorials[N], MOD - 2);

    for (int i = N - 1; i >= 1; i--)
    {
        iFactorials[i] = iFactorials[i + 1] * (i + 1) % MOD;
    }

    ll res = factorials[N] * iFactorials[K] % MOD;
    res = res * iFactorials[N - K] % MOD;

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}

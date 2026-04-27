#include <bits/stdc++.h>
using namespace std;

void solve()
{
    using ll = long long;
    int N;
    cin >> N;

    vector<ll> A(N), B(N), C(N), P(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i] >> C[i] >> P[i];
    }

    ll t = 1;
    ll a, b, c;
    a = b = c = 0;

    for (int i = 0; i < N; i++)
    {
        if (A[i] > a)
        {
            t += A[i] - a;
            a = A[i];
        }

        if (B[i] > b)
        {
            t += B[i] - b;
            b = B[i];
        }

        if (C[i] > c)
        {
            t += C[i] - c;
            c = C[i];
        }

        if (t > P[i])
        {
            cout << "NO" << '\n';
            return;
        }

        t++;
    }

    cout << "YES" << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    // 최소한으로 스탯을 올려서 문제를 해결할 때 마감기한이 넘어가는게 하나라도 나오면 불가능

    int T;
    cin >> T;

    while (--T >= 0)
    {
        solve();
    }

    // inputFileStream.close();
    return 0;
}
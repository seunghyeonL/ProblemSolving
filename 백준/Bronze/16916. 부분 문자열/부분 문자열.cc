#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    string S, P;
    cin >> S >> P;

    int N = S.size();
    int M = P.size();

    if (N < M)
    {
        cout << 0 << '\n';
        return 0;
    }

    using ull = unsigned long long;

    int B = 918237733;
    ull mx_pow_B = 1;
    for (int i = 1; i < M; i++)
        mx_pow_B *= B;

    ull h{}, ph{};
    for (int i = 0; i < M; i++)
    {
        h *= B;
        h += (S[i] - 'a');
    }

    for (int i = 0; i < M; i++)
    {
        ph *= B;
        ph += (P[i] - 'a');
    }

    int ans = 0;

    for (int l = 0, r = M; r <= N; l++, r++)
    {
        if (ph == h)
        {
            bool ok = true;
            for (int i = 0; i < M; i++)
            {
                if (P[i] != S[l + i])
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
            {
                cout << 1 << '\n';
                return 0;
            }
        }

        if (r == N)
            break;

        h -= mx_pow_B * (S[l] - 'a');
        h *= B;
        h += S[r] - 'a';
    }

    cout << 0 << '\n';

    // inputFileStream.close();
    return 0;
}

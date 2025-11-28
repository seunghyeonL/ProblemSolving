#include <bits/stdc++.h>
using namespace std;

const int NMX = 10000000;
int N;
int spf[NMX + 1];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        spf
    */

    cin >> N;

    spf[0] = 0;
    spf[1] = 1;

    for (int i = 2; i <= N; i += 2)
    {
        spf[i] = 2;
    }

    for (int i = 3; i <= N; i += 2)
    {
        if (spf[i])
            continue;

        spf[i] = i;

        for (long long j = (long long)i * i; j <= N; j += i)
        {
            if (!spf[j])
            {
                spf[j] = i;
            }
        }
    }

    while (spf[N] != N)
    {
        cout << spf[N] << '\n';

        N /= spf[N];
    }

    if (N > 1)
        cout << N << '\n';

    // inputFileStream.close();
    return 0;
}

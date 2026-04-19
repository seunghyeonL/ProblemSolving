#include <bits/stdc++.h>
using namespace std;

const int MX = 30;
int N, M;
long long C[MX][MX + 1];

void solve()
{
    cin >> N >> M;

    cout << C[M][N] << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int T;
    cin >> T;

    C[0][0] = 1;

    for (int n = 1; n < MX; n++)
    {
        for (int m = 0; m <= n + 1; m++)
        {
            if (m > 0)
                C[n][m] += C[n - 1][m - 1];

            if (m <= n)
                C[n][m] += C[n - 1][m];
        }
    }

    while (T-- > 0)
        solve();

    // inputFileStream.close();
    return 0;
}
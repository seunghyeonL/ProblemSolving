#include <bits/stdc++.h>
using namespace std;

string S, P;
int N, M;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> S >> P;

    N = S.size();
    M = P.size();
    int sz_mn = min(N, M);

    int ans = 0;
    for (int i = 0; i < M;) // P idx
    {
        int mx_len = 0;
        for (int lj = 0; lj < N; lj++) // S left idx
        {
            int ci = i;
            int cj = lj;
            int len = 0;

            while (ci < M && cj < N && P[ci] == S[cj])
            {
                ci++, cj++, len++;
            }

            mx_len = max(mx_len, len);
        }

        i += mx_len;
        ans++;
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
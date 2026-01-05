#include <bits/stdc++.h>
using namespace std;

string S, P;
int N, M;
vector<int> F;

bool kmp(string part)
{
    int sz = part.size();

    for (int i = 0, j = 0; i < N; i++)
    {
        while (j > 0 && S[i] != part[j])
            j = F[j - 1];

        if (S[i] == part[j])
            ++j;

        if (j == sz)
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

    cin >> S >> P;

    N = S.size();
    M = P.size();
    int sz_mn = min(N, M);
    F.resize(N);

    for (int i = 1, j = 0; i < N; i++)
    {
        while (j > 0 && S[i] != S[j])
            j = F[j - 1];

        if (S[i] == S[j])
            F[i] = ++j;
    }

    int ans = 0;
    for (int i = 0; i < M;)
    {
        for (int len = sz_mn; len >= 1; len--)
        {
            if (kmp(P.substr(i, len)))
            {
                ans++;
                i += len;
                break;
            }
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
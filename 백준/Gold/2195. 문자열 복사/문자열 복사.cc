#include <bits/stdc++.h>
using namespace std;

string S, P;
int N, M;

bool is_matched(int pi, int len)
{
    // l + len <= N
    for (int l = 0; l <= N - len; l++)
    {
        bool matched = true;
        for (int i = 0; i < len; i++)
        {
            if (S[l + i] != P[pi + i])
            {
                matched = false;
                break;
            }
        }

        if (matched)
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

    int ans = 0;
    for (int i = 0; i < M;)
    {
        for (int len = sz_mn; len >= 1; len--)
        {
            if (is_matched(i, len))
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
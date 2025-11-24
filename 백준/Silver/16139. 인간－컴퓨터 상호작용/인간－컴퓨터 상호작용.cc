#include <bits/stdc++.h>
using namespace std;

const int NMX = 200000;
string S;
int Q;
int ps[NMX + 1][26]; // ps[i][j] : [0, i) 범위의 j idx 알파펫 개수

void solve()
{
    char c;
    int l, r;
    cin >> c >> l >> r;

    int n = c - 'a';

    cout << ps[r + 1][n] - ps[l][n] << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> S >> Q;
    int sz = S.size();

    for (int i = 1; i <= sz; i++)
    {
        for (int j = 0; j < 26; j++)
            ps[i][j] = ps[i - 1][j];

        char c = S[i - 1];
        int n = c - 'a';

        ps[i][n]++;
    }

    for (int i = 0; i < Q; i++)
        solve();

    // inputFileStream.close();
    return 0;
}
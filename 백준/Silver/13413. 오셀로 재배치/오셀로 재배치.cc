#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
int N;

void solve()
{
    cin >> N;
    string line1;
    string line2;

    cin >> line1 >> line2;

    int w2b = 0;
    int b2w = 0;

    for (int i = 0; i < N; i++)
    {
        if (line1[i] == 'W' && line2[i] == 'B')
            w2b++;
        else if (line1[i] == 'B' && line2[i] == 'W')
            b2w++;
    }

    int mx = max(w2b, b2w);
    // int mn = min(w2b, b2w);

    cout << mx << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
     */

    int T;
    cin >> T;

    while (--T >= 0)
        solve();

    // inputFileStream.close();
    return 0;
}
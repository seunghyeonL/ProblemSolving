#include <bits/stdc++.h>
using namespace std;

int N, M;

void solve()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
    }

    cout << N - 1 << '\n';
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

    for (int i = 0; i < T; i++)
        solve();

    // inputFileStream.close();
    return 0;
}
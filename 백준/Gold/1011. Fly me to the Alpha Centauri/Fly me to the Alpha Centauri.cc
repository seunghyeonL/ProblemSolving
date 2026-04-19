#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;

    int dist = y - x;

    int ans = 0;

    while (true)
    {
        ans++;
        long long S = (long long)(ans + 1) * (ans + 1) / 4;
        if (S >= dist)
            break;
    }

    cout << ans << '\n';
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
        삼각형 너비
    */

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
        solve();

    // inputFileStream.close();
    return 0;
}
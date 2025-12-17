#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

ll cross(const P &v1, const P &v2)
{
    /*
        (x1, y1) X (x2, y2)
        x1 * y2 - y1 * x2
    */

    const auto &[x1, y1] = v1;
    const auto &[x2, y2] = v2;

    return x1 * y2 - x2 * y1;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    vector<P> pos;

    for (int i = 0; i < 3; i++)
    {
        int x, y;
        cin >> x >> y;
        pos.emplace_back(x, y);
    }

    ll ans = 0;
    for (int i = 0; i < 3; i++)
    {
        ans += cross(pos[i], pos[(i + 1) % 3]);
    }

    if (ans < 0)
        cout << -1;
    else if (ans == 0)
        cout << 0;
    else
        cout << 1;

    // inputFileStream.close();
    return 0;
}
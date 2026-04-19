#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

P operator-(const P &a, const P &b)
{
    const auto &[ax, ay] = a;
    const auto &[bx, by] = b;
    return {ax - bx, ay - by};
}

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
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        pos.emplace_back(x, y);
    }

    ll ans = 0;
    for (int i = 1; i < N - 1; i++)
    {
        ans += cross(pos[i] - pos[0], pos[i + 1] - pos[0]);
    }

    cout << fixed;
    cout.precision(1);
    cout << double(abs(ans)) / 2;

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll cross(const pair<ll, ll> &p1, const pair<ll, ll> &p2)
{
    auto &[x1, y1] = p1;
    auto &[x2, y2] = p2;
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

    ll x1, x2, x3, x4;
    ll y1, y2, y3, y4;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    pair<ll, ll> p1 = {x1, y1};
    pair<ll, ll> p2 = {x2, y2};
    pair<ll, ll> p3 = {x3, y3};
    pair<ll, ll> p4 = {x4, y4};

    ll ccw1 = cross(p1, p2) + cross(p2, p3) + cross(p3, p1);
    ll ccw2 = cross(p1, p2) + cross(p2, p4) + cross(p4, p1);
    ll ccw3 = cross(p3, p4) + cross(p4, p1) + cross(p1, p3);
    ll ccw4 = cross(p3, p4) + cross(p4, p2) + cross(p2, p3);

    int sign1 = ccw1 / abs(ccw1) * ccw2 / abs(ccw2);
    int sign2 = ccw3 / abs(ccw3) * ccw4 / abs(ccw4);

    cout << (sign1 < 0 && sign2 < 0);

    // inputFileStream.close();
    return 0;
}
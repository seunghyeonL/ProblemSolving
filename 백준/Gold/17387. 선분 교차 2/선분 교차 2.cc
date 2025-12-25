#include <bits/stdc++.h>
using namespace std;

using P = pair<__int128, __int128>;

__int128 cross(const P &p1, const P &p2)
{
    auto &[x1, y1] = p1;
    auto &[x2, y2] = p2;
    return (x1 * y2 - x2 * y1);
}

__int128 dot(const P &p1, const P &p2)
{
    auto &[x1, y1] = p1;
    auto &[x2, y2] = p2;
    return (x1 * x2 + y1 * y2);
}

P operator-(const P &p1, const P &p2)
{
    auto &[x1, y1] = p1;
    auto &[x2, y2] = p2;
    return {x1 - x2, y1 - y2};
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int x1, x2, x3, x4;
    int y1, y2, y3, y4;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    P p1 = {x1, y1};
    P p2 = {x2, y2};
    P p3 = {x3, y3};
    P p4 = {x4, y4};

    auto ccw1 = cross(p1, p2) + cross(p2, p3) + cross(p3, p1);
    auto ccw2 = cross(p1, p2) + cross(p2, p4) + cross(p4, p1);
    auto ccw3 = cross(p3, p4) + cross(p4, p1) + cross(p1, p3);
    auto ccw4 = cross(p3, p4) + cross(p4, p2) + cross(p2, p3);

    // 어느 세 점도 한 직선이 아닌 경우
    if (ccw1 != 0 && ccw2 != 0 && ccw3 != 0 && ccw4 != 0)
    {
        cout << (ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0);
        return 0;
    }

    // 한 점이 다른 선분 위
    if (ccw1 == 0 && dot(p2 - p3, p1 - p3) <= 0)
        cout << 1;
    else if (ccw2 == 0 && dot(p2 - p4, p1 - p4) <= 0)
        cout << 1;
    else if (ccw3 == 0 && dot(p3 - p1, p4 - p1) <= 0)
        cout << 1;
    else if (ccw4 == 0 && dot(p3 - p2, p4 - p2) <= 0)
        cout << 1;
    else
        cout << 0;

    // inputFileStream.close();
    return 0;
}
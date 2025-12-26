#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using P = pair<ld, ld>;

const ld pi = 3.14159265358;

int sgn(ld n)
{
    return (n > 0) - (n < 0);
}

ld cross(const P &p1, const P &p2)
{
    auto &[x1, y1] = p1;
    auto &[x2, y2] = p2;
    return (x1 * y2 - x2 * y1);
}

ld dot(const P &p1, const P &p2)
{
    auto &[x1, y1] = p1;
    auto &[x2, y2] = p2;
    return (x1 * x2 + y1 * y2);
}

P operator+(const P &p1, const P &p2)
{
    auto &[x1, y1] = p1;
    auto &[x2, y2] = p2;
    return {x1 + x2, y1 + y2};
}

P operator-(const P &p1, const P &p2)
{
    auto &[x1, y1] = p1;
    auto &[x2, y2] = p2;
    return {x1 - x2, y1 - y2};
}

P operator*(const P &p1, ld c)
{
    auto &[x1, y1] = p1;
    return {x1 * c, y1 * c};
}

P operator/(const P &p1, ld c)
{
    auto &[x1, y1] = p1;
    return {x1 / c, y1 / c};
}

P rotate90(const P &v)
{
    /*
        c -s
        s c

        x' = (0, -1)(x)
        y' = (1,  0)(y)

        x' = -y
        y = x;
    */

    return {-v.second, v.first};
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cout << fixed << setprecision(3);

    P C1{}, C2{};
    ld r1{}, r2{};

    cin >> C1.first >> C1.second >> r1 >> C2.first >> C2.second >> r2;

    if (r1 < r2)
    {
        swap(r1, r2);
        swap(C1, C2);
    }

    P D = C2 - C1;
    ld d = sqrt(dot(D, D));

    if (d > r1 + r2)
    {
        cout << 0.0 << '\n';
        return 0;
    }

    if (d < r1 - r2 + 0.00001)
    {
        cout << pi * r2 * r2 << '\n';
        return 0;
    }

    P Dn = D / d;
    ld a = (r1 * r1 - r2 * r2 + d * d) / (2 * d);
    ld b = d - a;
    ld h = sqrt(r1 * r1 - a * a);

    // 교점
    P P1 = C1 + Dn * a + rotate90(Dn) * h;
    P P2 = C1 + Dn * a - rotate90(Dn) * h;

    // 중심선, 교점 사이각 두배; 라디안
    ld th1 = acos(a / r1) * 2;
    ld th2 = acos(b / r2) * 2;

    // 부채꼴 넓이
    ld s1 = ld(1) / 2 * r1 * r1 * th1;
    ld s2 = ld(1) / 2 * r2 * r2 * th2;

    // 겹치는 다각형 넓이; 신발끈
    ld sp =
        abs(cross(C1, P1) + cross(P1, C2) + cross(C2, P2) + cross(P2, C1)) / 2;

    cout << (s1 + s2 - sp);

    // inputFileStream.close();
    return 0;
}
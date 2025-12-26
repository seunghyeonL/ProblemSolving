#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

int sgn(ll n)
{
    return (n > 0) - (n < 0);
}

ll cross(const P &p1, const P &p2)
{
    auto &[x1, y1] = p1;
    auto &[x2, y2] = p2;
    return (x1 * y2 - x2 * y1);
}

ll dot(const P &p1, const P &p2)
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

// NMX == 10000;
int N;
vector<P> A;    // 배리어 꼭지점
vector<P> B(3); // 피보호자

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;
    A.resize(N);

    for (int i = 0; i < N; i++)
        cin >> A[i].first >> A[i].second;

    for (int i = 0; i < 3; i++)
        cin >> B[i].first >> B[i].second;

    for (const auto &p : B)
    {
        bool on_side = false;
        for (int i = 0; i < N; i++)
        {
            const auto &p1 = A[i];
            const auto &p2 = A[(i + 1) % N];

            if (cross(p1 - p, p2 - p) == 0 && dot(p1 - p, p2 - p) <= 0)
            {
                on_side = true;
                break;
            }
        }

        if (on_side)
        {
            cout << 1 << '\n';
            continue;
        }

        int cnt_intersect = 0;
        const auto &[x, y] = p;
        for (int i = 0; i < N; i++)
        {
            auto [x1, y1] = A[i];
            auto [x2, y2] = A[(i + 1) % N];

            if (y1 > y2)
            {
                swap(y1, y2);
                swap(x1, x2);
            }

            // 반열림 구간, 교차점 x 범위(방정식 풀이)
            if (y > y1 && y <= y2 &&
                (y2 - y1) * x < (y2 - y1) * x1 + (y - y1) * (x2 - x1))
            {
                cnt_intersect++;
            }
        }

        if (cnt_intersect % 2 == 1)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    // inputFileStream.close();
    return 0;
}


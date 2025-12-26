#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

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

bool is_intersect(const P &p1, const P &p2, const P &p3, const P &p4)
{
    auto ccw1 = cross(p1, p2) + cross(p2, p3) + cross(p3, p1);
    auto ccw2 = cross(p1, p2) + cross(p2, p4) + cross(p4, p1);
    auto ccw3 = cross(p3, p4) + cross(p4, p1) + cross(p1, p3);
    auto ccw4 = cross(p3, p4) + cross(p4, p2) + cross(p2, p3);

    // 어느 세 점도 한 직선이 아닌 경우
    if (ccw1 != 0 && ccw2 != 0 && ccw3 != 0 && ccw4 != 0)
    {
        return (ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0);
    }

    // 한 점이 다른 선분 위
    if (ccw1 == 0 && dot(p2 - p3, p1 - p3) <= 0)
        return true;
    else if (ccw2 == 0 && dot(p2 - p4, p1 - p4) <= 0)
        return true;
    else if (ccw3 == 0 && dot(p3 - p1, p4 - p1) <= 0)
        return true;
    else if (ccw4 == 0 && dot(p3 - p2, p4 - p2) <= 0)
        return true;

    return false;
}

const int NMX = 3000;
int N;
vector<int> uf;

int find_root(int u)
{
    if (uf[u] < 0)
        return u;
    return uf[u] = find_root(uf[u]);
}

bool union_set(int u, int v)
{
    u = find_root(u);
    v = find_root(v);

    if (u == v)
        return false;

    // u -> v
    if (uf[u] < uf[v])
        swap(u, v);

    uf[v] += uf[u];
    uf[u] = v;

    return true;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;
    uf.assign(N, -1);

    vector<pair<P, P>> arr(N);
    for (int i = 0; i < N; i++)
    {
        P p1{}, p2{};
        cin >> p1.first >> p1.second >> p2.first >> p2.second;

        arr[i] = {p1, p2};
    }

    int group_cnt = N;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            const auto &[p1, p2] = arr[i];
            const auto &[p3, p4] = arr[j];
            if (is_intersect(p1, p2, p3, p4))
                if (union_set(i, j))
                    group_cnt--;
        }

    cout << group_cnt << '\n';
    cout << -1 * *min_element(uf.begin(), uf.end()) << '\n';

    // inputFileStream.close();
    return 0;
}
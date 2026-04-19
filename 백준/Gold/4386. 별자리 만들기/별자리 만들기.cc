#include <bits/stdc++.h>
using namespace std;

const int NMX = 100;
int N;
pair<double, double> arr[NMX + 1];
vector<tuple<double, int, int>> edge; // cost, u, v

int uf[NMX + 1];

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

    uf[v] = uf[u] + uf[v];
    uf[u] = v;

    return true;
}

double get_dist(int u, int v)
{
    auto [ux, uy] = arr[u];
    auto [vx, vy] = arr[v];
    return sqrt((ux - vx) * (ux - vx) + (uy - vy) * (uy - vy));
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
    for (int i = 1; i <= N; i++)
    {
        double x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }

    fill(uf, uf + N, -1);

    for (int u = 1; u <= N - 1; u++)
        for (int v = u + 1; v <= N; v++)
            edge.emplace_back(get_dist(u, v), u, v);

    sort(edge.begin(), edge.end());

    double ans = 0;
    int cnt = 0;

    for (auto [c, u, v] : edge)
    {
        if (union_set(u, v))
        {
            cnt++;
            ans += c;
        }

        if (cnt == N - 1)
            break;
    }

    cout << fixed;
    cout.precision(2);

    cout << ans << '\n';

    // inputFileStream.close();
    return 0;
}
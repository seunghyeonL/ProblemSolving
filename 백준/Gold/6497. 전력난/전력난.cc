#include <bits/stdc++.h>
using namespace std;

const int MX = 200000;
int M, N;
vector<tuple<int, int, int>> edges;

int uf[MX]; // 노드 0부터 시작

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

void solve()
{
    fill(uf, uf + M, -1);
    edges.clear();
    edges.reserve(N);

    int mx_cost = 0;
    for (int i = 0; i < N; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;

        edges.emplace_back(c, u, v);
        mx_cost += c;
    }

    sort(edges.begin(), edges.end());

    int mn_cost = 0;
    int cnt = 0;

    for (auto [c, u, v] : edges)
    {
        if (union_set(u, v))
        {
            cnt++;
            mn_cost += c;
        }

        if (cnt == M - 1)
            break;
    }

    cout << mx_cost - mn_cost << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    while (cin >> M >> N)
    {
        if (M == 0 && N == 0)
            break;

        solve();
    }

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int F;
int f_num = 0;
unordered_map<string, int> f_idx_map;
vector<int> uf;

int find_root(int u)
{
    if (uf[u] < 0)
        return u;

    return uf[u] = find_root(uf[u]);
}

int union_set(int u, int v)
{
    u = find_root(u);
    v = find_root(v);

    if (u == v)
        return -uf[u];

    // u -> v
    if (uf[u] < uf[v])
        swap(u, v);

    uf[v] += uf[u];
    uf[u] = v;

    return -uf[v];
}

void reset()
{
    f_num = 0;
    f_idx_map.clear();
    uf.clear();
}

void solve()
{
    reset();

    cin >> F;

    for (int i = 0; i < F; i++)
    {
        string a, b;
        cin >> a >> b;

        if (!f_idx_map.count(a))
        {
            f_idx_map[a] = f_num++;
            uf.push_back(-1);
        }

        if (!f_idx_map.count(b))
        {
            f_idx_map[b] = f_num++;
            uf.push_back(-1);
        }

        int a_idx = f_idx_map[a];
        int b_idx = f_idx_map[b];

        cout << union_set(a_idx, b_idx) << '\n';
    }
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int T;
    cin >> T;
    while (T-- > 0)
        solve();

    // inputFileStream.close();
    return 0;
}
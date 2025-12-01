#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000000;
int N, M;
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
    else if (uf[u] == uf[v])
        uf[v]--;

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

    cin >> N >> M;

    fill(uf, uf + N + 1, -1);

    for (int i = 0; i < M; i++)
    {
        int t, u, v;
        cin >> t >> u >> v;

        switch (t)
        {
        case 0:
            union_set(u, v);
            break;
        case 1:
            if (find_root(u) == find_root(v))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
            break;
        }
    }

    // inputFileStream.close();
    return 0;
}
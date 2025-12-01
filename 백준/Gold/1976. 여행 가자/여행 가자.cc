#include <bits/stdc++.h>
using namespace std;

const int NMX = 200;
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

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            bool is_connected;
            cin >> is_connected;

            if (is_connected)
                union_set(i, j);
        }

    int cur = 0;
    bool ans = true;

    for (int i = 0; i < M; i++)
    {
        int u;
        cin >> u;

        u = find_root(u);
        
        if (cur == 0) 
        {
            cur = u;
            continue;
        }

        if (cur != u)
        {
            ans = false;
            break;
        }
    }

    cout << (ans ? "YES" : "NO");

    // inputFileStream.close();
    return 0;
}
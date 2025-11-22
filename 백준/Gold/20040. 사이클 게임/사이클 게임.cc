#include <bits/stdc++.h>
using namespace std;

const int NMX = 500000;
const int MMX = 1000000;
int N, M;
pair<int, int> arr[MMX + 1];

int uf[NMX];

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

    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;

        arr[i] = {u, v};
    }

    fill(uf, uf + N, -1);

    int ans = 0;
    for (int i = 1; i <= M; i++)
    {
        auto [u, v] = arr[i];

        if (!union_set(u, v))
        {
            ans = i;
            break;
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
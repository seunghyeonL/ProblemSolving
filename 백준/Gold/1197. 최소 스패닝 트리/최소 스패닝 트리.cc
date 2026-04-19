#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        MST
        크루스칼
    */

    using T = tuple<int, int, int>;
    int N, E;
    cin >> N >> E;

    vector<T> edges(E);
    for (int i = 0; i < E; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;

        edges.emplace_back(c, u, v);
    }

    sort(edges.begin(), edges.end());

    vector<int> uf(N + 1, -1);

    function<int(int)> findRoot = [&](int u) -> int
    {
        if (uf[u] < 0)
            return u;

        return uf[u] = findRoot(uf[u]);
    };

    auto unionSet = [&](int u, int v) -> bool
    {
        u = findRoot(u);
        v = findRoot(v);

        if (u == v)
            return false;

        // u를 v에 붙일것
        if (uf[u] < uf[v])
            swap(u, v);
        else if (uf[u] == uf[v])
        {
            uf[v]--;
        }

        uf[u] = v;

        return true;
    };

    int res = 0;
    int cnt = 0;
    for (auto [c, u, v] : edges)
    {
        if (unionSet(u, v))
        {
            res += c;
            cnt++;
        }

        if (cnt == N - 1)
            break;
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}

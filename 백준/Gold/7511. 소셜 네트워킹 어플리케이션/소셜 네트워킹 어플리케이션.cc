#include <bits/stdc++.h>

using namespace std;

void solve()
{
    using P = pair<int, int>;
    int N, K;
    cin >> N >> K;

    vector<P> edges(K);

    for (int i = 0; i < K; i++)
    {
        cin >> edges[i].first;
        cin >> edges[i].second;
    }

    vector<int> uf(N, -1);

    function<int(int)> findRoot = [&](int u)
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

        // u를 v에 붙이기

        if (uf[u] < uf[v])
            swap(u, v);
        else if (uf[u] == uf[v])
            uf[v]--;

        uf[u] = v;

        return true;
    };

    for (auto [u, v] : edges)
    {
        unionSet(u, v);
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        if (findRoot(u) == findRoot(v))
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        union find
    */

    int T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        cout << "Scenario " << i << ":\n";
        solve();
        cout << '\n';
    }

    // inputFileStream.close();
    return 0;
}

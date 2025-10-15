#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000;
int N, M;
vector<pair<int, int>> nodes;
vector<int> uf;
vector<tuple<double, int, int>> edge; // dist, u, v

int findRoot(int u)
{
    if (uf[u] < 0)
        return u;
    return uf[u] = findRoot(uf[u]);
}

bool unionSet(int u, int v)
{
    u = findRoot(u);
    v = findRoot(v);

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

    /*
     */

    // ifstream inputFileStream("input.txt");

    cin >> N >> M;

    nodes.resize(N + 1);
    uf.resize(N + 1);
    fill(uf.begin(), uf.end(), -1);

    for (int i = 1; i <= N; i++)
    {
        int x, y;
        cin >> x >> y;

        nodes[i] = {x, y};
    }

    int cnt = 0;
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        if (unionSet(u, v))
            cnt++;
    }

    for (int u = 1; u <= N - 1; u++)
    {
        for (int v = u + 1; v <= N; v++)
        {
            auto [x1, y1] = nodes[u];
            auto [x2, y2] = nodes[v];
            double w = sqrt((long long)(x2 - x1) * (x2 - x1) +
                            (long long)(y2 - y1) * (y2 - y1));

            edge.emplace_back(w, u, v);
        }
    }

    sort(edge.begin(), edge.end());

    double dist = 0;

    for (auto [w, u, v] : edge)
    {
        if (cnt == N - 1)
            break;

        if (unionSet(u, v))
        {
            cnt++;
            dist += w;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << dist;

    // inputFileStream.close();
    return 0;
}
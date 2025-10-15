#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000;
int N, M, K;

vector<bool> eRoot;
vector<int> uf;
vector<tuple<int, int, int>> edge; // w, u, v

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

    if (eRoot[u] && eRoot[v])
        return false;

    // u -> v
    if (uf[u] < uf[v])
        swap(u, v);
    else if (uf[u] == uf[v])
        uf[v]--;

    if (eRoot[u])
    {
        eRoot[u] = false;
        eRoot[v] = true;
    }

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

    cin >> N >> M >> K;

    eRoot.resize(N + 1);
    uf.resize(N + 1);
    fill(uf.begin(), uf.end(), -1);

    for (int i = 0; i < K; i++)
    {
        int u;
        cin >> u;
        eRoot[u] = 1;
    }

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edge.emplace_back(w, u, v);
    }

    sort(edge.begin(), edge.end());

    int cnt = 0;
    int cost = 0;
    for (auto [w, u, v] : edge)
    {
        if (cnt == N - K)
            break;

        if (unionSet(u, v))
        {
            cnt++;
            cost += w;
        }
    }

    cout << cost;

    // inputFileStream.close();
    return 0;
}
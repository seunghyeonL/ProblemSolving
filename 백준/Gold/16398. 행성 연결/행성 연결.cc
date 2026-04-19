#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000;
int N, M;

vector<tuple<int, int, int>> edge; // w, u, v

vector<int> uf(NMX + 1, -1);

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

    // u를 v에 붙이기
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

    /*
     */

    cin >> N;

    for (int u = 1; u <= N; u++)
        for (int v = 1; v <= N; v++)
        {
            int w;
            cin >> w;
            if (w > 0 && u < v)
                edge.emplace_back(w, u, v);
        }

    sort(edge.begin(), edge.end());

    int cnt = 0;
    long long cost = 0;
    for (auto [w, u, v] : edge)
    {
        if (unionSet(u, v))
        {
            cost += w;

            if (++cnt == N - 1) break;
        }
    }

    cout << cost;
    // inputFileStream.close();
    return 0;
}
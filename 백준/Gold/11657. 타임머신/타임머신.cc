#include <bits/stdc++.h>
using namespace std;

const int NMX = 500;
const int MMX = 6000;
const int INF = 1e10;
int N, M;
vector<tuple<int, int, int>> E;
long long dist[NMX + 1]; // 1번 도시부터의 최단거리

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

    cin >> N >> M;
    fill(dist + 1, dist + N + 1, INF);
    dist[1] = 0;

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        E.emplace_back(u, v, w);
    }

    for (int step = 1; step <= N - 1; step++)
    {
        bool updated = false;
        for (auto [u, v, w] : E)
        {
            if (dist[u] == INF)
                continue;

            if (dist[v] > dist[u] + w)
            {
                updated = true;
                dist[v] = dist[u] + w;
            }
        }

        if (!updated)
            break;
    }

    bool has_negative_cycle = false;
    for (auto [u, v, w] : E)
    {
        if (dist[u] == INF)
            continue;

        if (dist[v] > dist[u] + w)
        {
            has_negative_cycle = true;
            break;
        }
    }

    if (has_negative_cycle)
        cout << -1;
    else
    {
        for (int i = 2; i <= N; i++)
            cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
    }

    // inputFileStream.close();
    return 0;
}
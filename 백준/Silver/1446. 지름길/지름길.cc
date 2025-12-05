#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
const int INF = 1000'000'000;
const int DMX = 10000;
int N, D;
int dist[DMX + 1];
vector<P> adj[DMX + 1];

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

    cin >> N >> D;
    fill(dist, dist + D + 1, INF);

    for (int i = 0; i < N; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].emplace_back(w, v);
    }

    priority_queue<P, vector<P>, greater<P>> pq; // 이동거리, 위치
    dist[0] = 0;
    pq.emplace(0, 0);

    while (!pq.empty())
    {
        auto [d, cx] = pq.top();
        pq.pop();

        if (cx == D)
            break;

        if (d > dist[cx])
            continue;

        {
            int nx = cx + 1;
            if (dist[nx] > dist[cx] + 1)
            {
                dist[nx] = dist[cx] + 1;
                pq.emplace(dist[nx], nx);
            }
        }

        for (auto [w, nx] : adj[cx])
        {
            if (dist[nx] > dist[cx] + w)
            {
                dist[nx] = dist[cx] + w;
                pq.emplace(dist[nx], nx);
            }
        }
    }

    cout << dist[D] << '\n';

    // inputFileStream.close();
    return 0;
}
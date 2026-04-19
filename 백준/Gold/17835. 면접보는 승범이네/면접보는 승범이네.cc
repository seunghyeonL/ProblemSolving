#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, int>;
const ll INF = 1e18;
const int NMX = 100000;
int N, M, K;

vector<pair<int, int>> adj[NMX + 1];
ll dist[NMX + 1];

void initDist()
{
    fill(dist + 1, dist + N + 1, INF);
}

void dijkstra()
{
    initDist();

    priority_queue<P, vector<P>, greater<P>> pq;

    for (int i = 0; i < K; i++)
    {
        int k;
        cin >> k;

        dist[k] = 0;
        pq.emplace(0, k);
    }

    while (!pq.empty())
    {
        auto [d, cv] = pq.top();
        pq.pop();

        if (d > dist[cv])
            continue;

        for (auto [w, nv] : adj[cv])
        {
            if (d + w < dist[nv])
            {
                dist[nv] = d + w;
                pq.emplace(d + w, nv);
            }
        }
    }
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

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[v].emplace_back(w, u);
    }

    dijkstra();

    auto it = max_element(dist + 1, dist + N + 1);

    cout << it - dist << '\n';
    cout << *it;

    // inputFileStream.close();
    return 0;
}
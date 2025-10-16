#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const int NMX = 800;
int N, E, v1, v2;
vector<P> adj[NMX + 1]; // w, v
int dist[NMX + 1];

vector<int> ans;

void resetDist()
{
    for (int i = 1; i <= N; i++)
        dist[i] = INF;
}

void dijkstra(int sv)
{
    resetDist();
    priority_queue<P, vector<P>, greater<P>> pq; // d, cv

    pq.emplace(0, sv);
    dist[sv] = 0;

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
                pq.emplace(d + w, nv);
                dist[nv] = d + w;
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

    /*
     */

    // ifstream inputFileStream("input.txt");

    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }

    cin >> v1 >> v2;
    dijkstra(1);
    ll sv1 = dist[v1];
    ll sv2 = dist[v2];

    dijkstra(v1);
    ll v1e = dist[N];
    ll v1v2 = dist[v2];

    dijkstra(v2);
    ll v2e = dist[N];
    ll v2v1 = dist[v1];

    ll ans = min(sv1 + v1v2 + v2e, sv2 + v2v1 + v1e);

    cout << (ans < INF ? ans : -1);
    // inputFileStream.close();
    return 0;
}
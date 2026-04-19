#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
const int INF = 1e9;
const int NMX = 1000;
int N, M, X;
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

    cin >> N >> M >> X;
    ans.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(w, v);
    }

    dijkstra(X);
    for (int u = 1; u <= N; u++)
    {
        ans[u] = dist[u];
    }

    for (int u = 1; u <= N; u++)
    {
        dijkstra(u);
        ans[u] += dist[X];
    }

    cout << *max_element(ans.begin() + 1, ans.end());

    // inputFileStream.close();
    return 0;
}
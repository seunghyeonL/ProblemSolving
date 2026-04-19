#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
const int INF = 1e9;
const int NMX = 2000;

vector<P> adj[NMX + 1]; // w, v
int dist_s[NMX + 1];
int dist_g[NMX + 1];
int dist_h[NMX + 1];

vector<int> targets;

void reset(int N)
{
    for (int i = 1; i <= N; i++)
        adj[i].clear();

    fill(dist_s + 1, dist_s + N + 1, INF);
    fill(dist_g + 1, dist_g + N + 1, INF);
    fill(dist_h + 1, dist_h + N + 1, INF);
    targets.clear();
}

void dijkstra(int sv, int *dist)
{
    priority_queue<P, vector<P>, greater<P>> pq; // sv로부터의 거리, cv
    dist[sv] = 0;
    pq.emplace(0, sv);

    while (!pq.empty())
    {
        auto [d, cv] = pq.top();
        pq.pop();

        if (dist[cv] < d)
            continue;

        for (auto [w, nv] : adj[cv])
        {
            int nd = d + w;

            if (dist[nv] > nd)
            {
                dist[nv] = nd;
                pq.emplace(nd, nv);
            }
        }
    }
}

void solve()
{
    int N, M, T, s, g, h;
    cin >> N >> M >> T >> s >> g >> h;
    reset(N);

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }

    for (int i = 0; i < T; i++)
    {
        int tv;
        cin >> tv;
        targets.push_back(tv);
    }

    dijkstra(s, dist_s);
    dijkstra(g, dist_g);
    dijkstra(h, dist_h);

    vector<int> ans;

    for (int tv : targets)
    {
        if (dist_s[tv] == min(dist_s[g] + dist_g[h] + dist_h[tv],
                              dist_s[h] + dist_h[g] + dist_g[tv]))
            ans.push_back(tv);
    }

    sort(ans.begin(), ans.end());
    for (int el : ans)
        cout << el << ' ';
    cout << '\n';
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

    int tn;
    cin >> tn;

    while (tn-- > 0)
        solve();

    // inputFileStream.close();
    return 0;
}
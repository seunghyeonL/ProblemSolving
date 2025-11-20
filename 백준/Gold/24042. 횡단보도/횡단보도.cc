#include <bits/stdc++.h>
using namespace std;

using P = pair<long long, int>;
const int NMX = 100000;
const long long INF = 1e18;

int N, M;
vector<P> adj[NMX + 1]; // 초록불 시간, 노드
long long dist[NMX + 1];

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

    for (int t = 0; t < M; t++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(t, v);
        adj[v].emplace_back(t, u);
    }

    priority_queue<P, vector<P>, greater<P>> pq; // 현재 시간, 현재 노드

    dist[1] = 0;
    pq.emplace(0, 1);

    while (!pq.empty())
    {
        auto [ct, cv] = pq.top();
        pq.pop();

        if (dist[cv] < ct)
            continue;

        for (auto [t, nv] : adj[cv])
        {
            // ct + waiting == t (mod M)
            long long waiting = (t - ct) % M;
            if (waiting < 0)
                waiting += M;

            long long nt = ct + waiting + 1;

            if (dist[nv] > nt)
            {
                dist[nv] = nt;
                pq.emplace(nt, nv);
            }
        }
    }

    cout << dist[N];

    // inputFileStream.close();
    return 0;
}
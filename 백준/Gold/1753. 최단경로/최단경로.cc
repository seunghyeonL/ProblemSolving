#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        다익스트라
    */

    using P = pair<int, int>;
    int N, E;
    cin >> N >> E;

    int K;
    cin >> K;

    // 비용, 노드
    vector<vector<P>> adj(N + 1);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].emplace_back(w, v);
    }

    vector<int> dist(N + 1, 1e9);

    // 시작점으로부터 거리, 노드
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, K);
    dist[K] = 0;

    while (!pq.empty())
    {
        auto [cw, cv] = pq.top();
        pq.pop();

        if (cw > dist[cv])
            continue;

        for (auto [dw, nv] : adj[cv])
        {
            int nw = cw + dw;
            if (dist[nv] > nw)
            {
                dist[nv] = nw;
                pq.emplace(nw, nv);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == 1e9)
        {
            cout << "INF" << '\n';
        }
        else
        {
            cout << dist[i] << '\n';
        }
    }

    // inputFileStream.close();
    return 0;
}

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
        경로복원
    */

    using P = pair<int, int>;
    int N, M;
    cin >> N >> M;

    vector<vector<P>> adj(N + 1);

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].emplace_back(w, v);
    }

    int start, dest;
    cin >> start >> dest;

    vector<int> dist(N + 1, 1e9);
    vector<int> pre(N + 1);

    // start부터의 거리, 노드
    priority_queue<P, vector<P>, greater<P>> pq;

    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty())
    {
        auto [cw, cv] = pq.top();
        pq.pop();

        if (cw > dist[cv])
            continue;

        if (cv == dest)
        {
            break;
        }

        for (auto [dw, nv] : adj[cv])
        {
            int nw = cw + dw;
            if (nw < dist[nv])
            {
                dist[nv] = nw;
                pre[nv] = cv;
                pq.emplace(nw, nv);
            }
        }
    }

    cout << dist[dest] << '\n';
    vector<int> history;
    int h = dest;
    while (h != start)
    {
        history.push_back(h);
        h = pre[h];
        if (h == start)
        {
            history.push_back(h);
        }
    }

    cout << history.size() << '\n';

    for (int i = history.size() - 1; i >= 0; i--)
    {
        cout << history[i] << ' ';
    }
    cout << '\n';

    // inputFileStream.close();
    return 0;
}

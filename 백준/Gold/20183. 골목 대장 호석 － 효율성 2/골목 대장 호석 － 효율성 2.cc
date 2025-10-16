#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using E = pair<int, ll>;
using P = pair<int, int>;
using T = tuple<int, ll, int>;

const int EINF = 1e9 + 1;
const ll INF = 1e18;
const int NMX = 100000;
int N, M, A, B;
ll C;
vector<P> adj[NMX + 1];

// 시작점 -> u 로 가는 경로의 {최대 수치심을 주는 수급량, 총 수급량}
E dist[NMX + 1];

void initDist()
{
    for (int u = 1; u <= N; u++)
    {
        dist[u] = {EINF, INF};
    }
}

void dijkstra(int sv)
{
    initDist();

    priority_queue<T, vector<T>, greater<T>> pq;

    dist[sv] = {0, 0};
    pq.emplace(0, 0, sv);

    while (!pq.empty())
    {
        auto [mxe, total, cv] = pq.top();
        pq.pop();

        if (mxe > dist[cv].first)
            continue;

        for (auto [w, nv] : adj[cv])
        {
            if (total + w > C)
                continue;

            if (max(mxe, w) < dist[nv].first)
            {
                dist[nv] = {max(mxe, w), total + w};
                pq.emplace(max(mxe, w), total + w, nv);
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

    cin >> N >> M >> A >> B >> C;

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }

    dijkstra(A);
    int ans = dist[B].first;

    cout << (ans == EINF ? -1 : ans);

    // inputFileStream.close();
    return 0;
}
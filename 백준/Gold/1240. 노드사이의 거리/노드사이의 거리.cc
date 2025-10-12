#include <bits/stdc++.h>
using namespace std;

using T = tuple<int, int, int>;
using P = pair<int, int>;
const int NMX = 1000;
int N, M;
vector<P> adj[NMX + 1]; // 가중치, 노드

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    // ifstream inputFileStream("input.txt");
    for (int i = 0; i < N - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        int ans{};
        queue<T> q; // cv, pv, dist
        q.emplace(u, 0, 0);

        while (!q.empty())
        {
            auto [cv, pv, dist] = q.front();
            q.pop();

            if (cv == v)
            {
                ans = dist;
                break;
            }

            for (auto [w, nv] : adj[cv])
            {
                if (nv == pv)
                    continue;

                q.emplace(nv, cv, dist + w);
            }
        }

        cout << ans << '\n';
    }

    // inputFileStream.close();
    return 0;
}
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
        dfs, bfs 구현
    */

    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (auto &nvs : adj)
    {
        sort(nvs.begin(), nvs.end());
    }

    vector<bool> visited(N + 1);

    auto bfs = [&]()
    {
        queue<int> q;
        visited[V] = true;
        q.push(V);

        while (!q.empty())
        {
            int cv = q.front();
            q.pop();

            cout << cv << ' ';

            for (int nv : adj[cv])
            {
                if (visited[nv])
                    continue;

                visited[nv] = true;
                q.push(nv);
            }
        }
    };

    function<void(int)> dfs = [&](int cv)
    {
        if (visited[cv])
            return;
        visited[cv] = true;
        cout << cv << ' ';

        for (int nv : adj[cv])
        {
            dfs(nv);
        }
    };

    dfs(V);
    cout << '\n';
    fill(visited.begin(), visited.end(), false);
    bfs();

    // inputFileStream.close();
    return 0;
}

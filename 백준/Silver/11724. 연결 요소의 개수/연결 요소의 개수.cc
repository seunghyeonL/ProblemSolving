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
        클러스터 개수 찾기
    */

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(N + 1);

    function<bool(int)> dfs = [&](int cv)
    {
        if (visited[cv])
            return false;

        visited[cv] = true;

        for (int nv : adj[cv])
        {
            dfs(nv);
        }

        return true;
    };

    int res = 0;
    for (int i = 1; i <= N; i++)
    {
        if (dfs(i))
            res++;
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}

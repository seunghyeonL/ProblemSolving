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
        노드의 트리 부모 찾기
        각 노드의 트리 부모 배열 만들기
    */

    int N;
    cin >> N;

    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parents(N + 1);

    function<void(int, int)> dfs = [&](int cv, int pv)
    {
        parents[cv] = pv;

        for (int nv : adj[cv])
        {
            if (nv == pv)
                continue;

            dfs(nv, cv);
        }
    };

    dfs(1, 0);

    for (int i = 2; i <= N; i++)
    {
        cout << parents[i] << '\n';
    }

    // inputFileStream.close();
    return 0;
}

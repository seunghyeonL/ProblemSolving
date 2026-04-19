#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
int N, R, Q;

vector<int> adj[NMX + 1];
int dp[NMX + 1]; // dp[u] : u서브트리의 정점 개수

void dfs(int cv, int pv)
{
    dp[cv] = 1;
    for (int nv : adj[cv])
    {
        if (nv == pv)
            continue;

        dfs(nv, cv);
        dp[cv] += dp[nv];
    }
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> R >> Q;

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(R, 0);

    for (int i = 0; i < Q; i++)
    {
        int u;
        cin >> u;

        cout << dp[u] << '\n';
    }

    // inputFileStream.close();
    return 0;
}

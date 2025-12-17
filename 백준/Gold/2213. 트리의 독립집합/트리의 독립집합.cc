#include <bits/stdc++.h>
using namespace std;

const int NMX = 10000;
int N;
int W[NMX + 1]; // 각 노드 가중치
vector<int> adj[NMX + 1];

// his[u][독립집합 여부] : 그때 더해진 자식노드 정보
vector<pair<int, int>> nxt[NMX + 1][2];

// dp[u][0] : u가 최대 독립집합의 원소가 아닐때 u 서브트리 독립집합 크기
// dp[u][1] : u가 최대 독립집합의 원소일때 u 서브트리 독립집합 크기
// dp[pv][0] = sum max(dp[cv][0], dp[cv][1])
// dp[pv][1] = sum dp[cv][0]
int dp[NMX + 1][2];

void dfs(int cv, int pv)
{
    dp[cv][1] = W[cv];

    for (int nv : adj[cv])
    {
        if (nv == pv)
            continue;

        dfs(nv, cv);

        if (dp[nv][0] < dp[nv][1])
        {
            dp[cv][0] += dp[nv][1];
            nxt[cv][0].emplace_back(nv, 1);
        }
        else
        {
            dp[cv][0] += dp[nv][0];
            nxt[cv][0].emplace_back(nv, 0);
        }

        dp[cv][1] += dp[nv][0];
        nxt[cv][1].emplace_back(nv, 0);
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

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> W[i];

    for (int i = 1; i <= N - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    int contain1 = dp[1][0] < dp[1][1];

    int ans = contain1 ? dp[1][1] : dp[1][0];
    vector<int> his;

    queue<pair<int, int>> q;

    q.emplace(1, contain1);

    while (!q.empty())
    {
        auto [cv, cb] = q.front();
        q.pop();

        if (cb)
            his.push_back(cv);

        for (auto [nv, nb] : nxt[cv][cb])
        {
            q.emplace(nv, nb);
        }
    }

    sort(his.begin(), his.end());

    cout << ans << '\n';
    for (int el : his)
        cout << el << ' ';
    cout << '\n';
    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int NMX = 300'000;
int N;
vector<P> adj[NMX + 1]; // 1 base
int node_cnt[NMX + 1];  // 1을 루트로 볼때 i 서브트리의 노드 개수
ll dp[NMX + 1];  // dp[i] : i 서브트리의 루트 i와 서브트리의 다른 노드들 사이
                 // 거리 총합
ll ans[NMX + 1]; // i와 다른 모든 노드 사이의 거리 총합

void set_node_cnt(int cv, int pv)
{
    int cur = 1;

    for (auto [w, nv] : adj[cv])
    {
        if (nv == pv)
            continue;

        set_node_cnt(nv, cv);

        cur += node_cnt[nv];
    }

    node_cnt[cv] = cur;
}

void set_dp(int cv, int pv)
{
    ll cur = 0;

    for (auto [w, nv] : adj[cv])
    {
        if (nv == pv)
            continue;

        set_dp(nv, cv);

        cur += dp[nv] + w * node_cnt[nv];
    }

    dp[cv] = cur;
}

void set_ans(int cv, int pv)
{
    ans[cv] += dp[cv];

    for (auto [w, nv] : adj[cv])
    {
        if (nv == pv)
            continue;

        ans[nv] += ans[cv] - (dp[nv] + node_cnt[nv] * w) +
                   (node_cnt[1] - node_cnt[nv]) * w;

        set_ans(nv, cv);
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

    for (int i = 0; i < N - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }

    set_node_cnt(1, 0);
    set_dp(1, 0);
    set_ans(1, 0);

    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int N, K;
    cin >> N >> K;

    vector<int> D(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> D[i];
    }

    // 들어오는 노드들 연결
    vector<vector<int>> inAdj(N + 1);

    for (int i = 0; i < K; i++)
    {
        int u, v;
        cin >> u >> v;

        inAdj[v].push_back(u);
    }

    vector<int> memo(N + 1, -1);

    function<int(int)> getBuildTime = [&](int cv)
    {
        if (memo[cv] > -1)
            return memo[cv];

        int res = 0;
        for (int nv : inAdj[cv])
        {
            res = max(res, getBuildTime(nv));
        }

        res += D[cv];

        return memo[cv] = res;
    };

    int W;
    cin >> W;

    cout << getBuildTime(W) << '\n';
};

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        방향그래프 dfs + memoization
    */

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve();
    }

    // inputFileStream.close();
    return 0;
}

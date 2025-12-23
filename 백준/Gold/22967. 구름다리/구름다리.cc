#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        (N - 1) * N / 2 개를 연결하면 R = 1

        N - 1 * N / 2 <= 2 * (N - 1)
        N <= 4

        N <= 4일때 모든 노드를 연결해서 지름을 1로 만들기

        N > 4일때는
        한 노드를 다른 모든 노드랑 연결해서 지름을 2로 만들기
    */

    const int NMX = 300;
    bool adj[NMX + 1][NMX + 1];
    memset(adj, false, sizeof(adj));

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u][v] = true;
        adj[v][u] = true;
    }

    if (N <= 4)
    {
        cout << N * (N - 1) / 2 - (N - 1) << '\n';
        cout << 1 << '\n';

        for (int u = 1; u <= N; u++)
            for (int v = u + 1; v <= N; v++)
            {
                if (adj[u][v])
                    continue;

                cout << u << ' ' << v << '\n';
            }
    }
    else
    {
        vector<pair<int, int>> ans;

        for (int u = 2; u <= N; u++)
        {
            if (adj[1][u])
                continue;

            ans.emplace_back(1, u);
        }

        cout << ans.size() << '\n';
        cout << 2 << '\n';
        for (auto &[u, v] : ans)
            cout << u << ' ' << v << '\n';
    }

    // inputFileStream.close();
    return 0;
}
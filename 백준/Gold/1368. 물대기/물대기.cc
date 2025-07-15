#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    // 우물을 파는것을 하나의 노드로 두고
    // 다른 노드와의 연결 가중치를 우물파는 비용으로 두고
    // MST 만들기

    int N;
    cin >> N;

    // 비용, 노드, 노드
    vector<vector<int>> roadCosts;
    vector<int> wellCosts(N + 1);

    for (int i = 0; i < N; i++)
    {
        cin >> wellCosts[i];
    }
    wellCosts[N] = 0;

    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            if (i == N && j == N)
            {
                roadCosts.push_back({wellCosts[N], N, N});
                continue;
            }
            else if (i == N)
            {
                roadCosts.push_back({wellCosts[j], N, j});
                continue;
            }
            else if (j == N)
            {
                roadCosts.push_back({wellCosts[i], i, N});
                continue;
            }

            int cost;
            cin >> cost;
            roadCosts.push_back({cost, i, j});
        }
    }

    sort(roadCosts.begin(), roadCosts.end(), [](vector<int> a, vector<int> b)
         { return a[0] < b[0]; });

    vector<int> p(N + 1, -1);

    function<int(int)> findRoot = [&](int u)
    {
        if (p[u] < 0)
        {
            return u;
        }

        return p[u] = findRoot(p[u]);
    };

    auto unionSet = [&](int u, int v) -> bool
    {
        int rootU = findRoot(u);
        int rootV = findRoot(v);

        if (rootU == rootV)
            return false;

        p[rootV] = rootU;
        return true;
    };

    int answer = 0;
    int connectedNum = 0;

    for (auto roadCost : roadCosts)
    {
        int cost = roadCost[0];
        int u = roadCost[1];
        int v = roadCost[2];

        if (unionSet(u, v))
        {
            answer += cost;
            if (++connectedNum == N)
                break;
        }
    }

    cout << answer;

    // inputFileStream.close();
    return 0;
}

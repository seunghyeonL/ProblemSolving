#include <bits/stdc++.h>
using namespace std;

const int NMX = 10000;
int N;
vector<pair<int, int>> adj[NMX + 1]; // 가중치, 노드

int getFarNode(int sv)
{
    queue<tuple<int, int, int>> q; // 시작점과의 거리, 현재 노드, 부모노드
    q.emplace(0, sv, 0);

    int mxDist = 0;
    int fv{};

    while (!q.empty())
    {
        auto [dist, cv, pv] = q.front();
        q.pop();

        if (mxDist < dist)
        {
            mxDist = dist;
            fv = cv;
        }

        for (auto [w, nv] : adj[cv])
        {
            if (nv == pv)
                continue;

            q.emplace(dist + w, nv, cv);
        }
    }

    return fv;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        트리의 한 노드에서 가장 먼 노드가 지름을 이루는 끝 노드 중 하나
    */

    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int p, c, w;
        cin >> p >> c >> w;

        adj[p].emplace_back(w, c);
        adj[c].emplace_back(w, p);
    }

    int diaNode1 = getFarNode(1);
    int diaNode2 = getFarNode(diaNode1);

    queue<tuple<int, int, int>> q; // 시작점과의 거리, 현재 노드, 부모노드
    q.emplace(0, diaNode1, 0);

    int ans{};
    while (!q.empty())
    {
        auto [dist, cv, pv] = q.front();
        q.pop();

        if (cv == diaNode2)
        {
            ans = dist;
            break;
        }

        for (auto [w, nv] : adj[cv])
        {
            if (nv == pv)
                continue;

            q.emplace(dist + w, nv, cv);
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
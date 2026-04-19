#include <bits/stdc++.h>
using namespace std;
const int NMX = 500;
int N, M;
vector<int> adj[NMX + 1];
bool vis[NMX + 1];
queue<pair<int, int>> q;

void resetAdj()
{
    for (int i = 1; i <= N; i++)
    {
        adj[i].clear();
    }
}

void resetVisited()
{
    fill(vis + 1, vis + N + 1, false);
}

bool hasCycle(int sv)
{
    bool res = false;
    q.emplace(sv, 0);
    vis[sv] = true;

    while (!q.empty())
    {
        auto [cv, pv] = q.front();
        q.pop();

        for (int nv : adj[cv])
        {
            if (pv == nv)
                continue;

            if (vis[nv])
            {
                res = true;
                continue;
            }

            vis[nv] = true;
            q.emplace(nv, cv);
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int test = 0;
    while (cin >> N >> M)
    {
        test++;
        if (N == 0 && M == 0)
            break;
        resetAdj();
        resetVisited();

        for (int i = 0; i < M; i++)
        {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int treeCnt = 0;
        for (int u = 1; u <= N; u++)
        {
            if (vis[u])
                continue;

            if (!hasCycle(u))
                treeCnt++;
        }

        switch (treeCnt)
        {
        case 0:
            cout << "Case " << test << ": No trees." << '\n';
            break;
        case 1:
            cout << "Case " << test << ": There is one tree." << '\n';
            break;
        default:
            cout << "Case " << test << ": A forest of " << treeCnt << " trees."
                 << '\n';
        }
    }

    // inputFileStream.close();
    return 0;
}
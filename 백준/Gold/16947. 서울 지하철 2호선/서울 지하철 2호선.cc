#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> adj[3001];
int deg[3001];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
     */

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    vector<int> distFromCycle(N + 1, -1);
    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        // leaf
        if (deg[i] == 1)
        {
            q.push(i);
        }
    }

    // leaf pruning
    while (!q.empty())
    {
        int cv = q.front();
        q.pop();

        deg[cv] = 0;

        for (int nv : adj[cv])
        {
            if (deg[nv] > 0 && --deg[nv] == 1)
                q.push(nv);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (deg[i] > 1)
        {
            q.push(i);
            distFromCycle[i] = 0;
        }
    }

    // 가지 depth 채우기
    while (!q.empty())
    {
        auto cv = q.front();
        q.pop();

        for (int nv : adj[cv])
        {
            if (distFromCycle[nv] == -1)
            {
                distFromCycle[nv] = distFromCycle[cv] + 1;
                q.push(nv);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << distFromCycle[i] << ' ';
    }
    cout << '\n';

    // inputFileStream.close();
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

const int NMX = 32000;
int N, M;
int indeg[NMX + 1];
vector<int> adj[NMX + 1];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     */

    // ifstream inputFileStream("input.txt");

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v; // u보다 v가 늦게 풀어야함
        cin >> u >> v;

        adj[u].push_back(v);
        indeg[v]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int u = 1; u <= N; u++)
    {
        if (indeg[u] == 0)
        {
            pq.push(u);
        }
    }

    while (!pq.empty())
    {
        int cv = pq.top();
        pq.pop();

        cout << cv << ' ';

        for (int nv : adj[cv])
        {
            if (--indeg[nv] == 0)
                pq.push(nv);
        }
    }

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000;
const int MMX = 100;
int N, M;

vector<int> adj[NMX + 1];
int indeg[NMX + 1];

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

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int j = 0; j < n; j++)
            cin >> v[j];

        for (int j = 1; j < n; j++)
        {
            adj[v[j - 1]].push_back(v[j]);
            indeg[v[j]]++;
        }
    }

    // for (int u = 1; u <= N; u++)
    //     cout << indeg[u] << '\n';

    queue<int> q;
    for (int u = 1; u <= N; u++)
    {
        if (indeg[u] == 0)
            q.push(u);
    }

    vector<int> ans;
    while (!q.empty())
    {
        int cv = q.front();
        q.pop();

        ans.push_back(cv);

        for (int nv : adj[cv])
        {
            if (--indeg[nv] == 0)
            {
                q.push(nv);
            }
        }
    }

    if (ans.size() < N)
        cout << 0;
    else
        for (int el : ans)
            cout << el << '\n';

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin >> N;

    vector<int> adj(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> adj[i];

    vector<bool> visited(N + 1);
    int teamCnt = 0;

    auto check = [&](int cv)
    {
        vector<int> sel{cv};
        visited[cv] = true;

        while (1)
        {
            int nv = adj[cv];

            if (visited[nv])
            {
                auto it = find(sel.begin(), sel.end(), nv);
                teamCnt += sel.end() - it;
                break;
            }

            sel.push_back(nv);
            visited[nv] = true;
            cv = nv;
        }
    };

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            check(i);
        }
    }

    cout << N - teamCnt << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int T;
    cin >> T;

    for (int _ = 0; _ < T; _++)
    {
        solve();
    }

    // inputFileStream.close();
    return 0;
}
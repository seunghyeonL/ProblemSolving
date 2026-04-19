#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000000;
int N;
vector<int> adj[NMX + 1];
bool isEarly[NMX + 1];

void dfs(int cv, int pv)
{
    bool needEarly = false;
    for (int nv : adj[cv])
    {
        if (nv == pv)
            continue;
        dfs(nv, cv);

        if (!isEarly[nv])
            needEarly = true;
    }

    isEarly[cv] = needEarly;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        leaf는 얼리어답터일 필요가 없다
        (leaf가 얼리어답터 대신 부모가 얼리어답터로 설정하면 항상 이득)
    */

    // ifstream inputFileStream("input.txt");

    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    int ans = 0;
    for (int i = 1; i <= N; i++)
        if (isEarly[i])
            ans++;

    cout << ans << '\n';
    // inputFileStream.close();
    return 0;
}
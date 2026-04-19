#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
int N, M;
vector<int> uf(NMX + 1, -1);

int findRoot(int u)
{
    if (uf[u] < 0)
        return u;
    return uf[u] = findRoot(uf[u]);
}

bool unionSet(int u, int v)
{
    u = findRoot(u);
    v = findRoot(v);

    if (u == v)
        return false;

    // u를 v에 붙이기
    if (uf[u] < uf[v])
        swap(u, v);
    else if (uf[u] == uf[v])
        uf[v]--;

    uf[u] = v;

    return true;
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
        union find로 연결하면서
        이미 연결된걸 연결하면 끊는 연산(ans++)

        다 연결하고
        덩어리 개수를 찾아서 그 개수만큼 합치는 연산(ans++)
    */

    cin >> N >> M;

    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        if (!unionSet(u, v))
        {
            ans++;
        }
    }

    set<int> clusterRoot;
    for (int u = 1; u <= N; u++)
        clusterRoot.insert(findRoot(u));

    int clusterNum = clusterRoot.size();

    ans += clusterNum - 1;

    cout << ans << '\n';

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000000;
int N, M;

int uf[NMX + 1];
int rw[NMX + 1]; // 합쳐진 방의 오른쪽 끝

void init()
{
    fill(uf + 1, uf + N + 1, -1);

    for (int i = 1; i <= N; i++)
    {
        rw[i] = i;
    }
}

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

    // u -> v
    if (uf[u] < uf[v])
        swap(u, v);
    else if (uf[u] == uf[v])
        uf[v]--;

    rw[v] = max(rw[u], rw[v]);
    rw[u] = rw[v];

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
     */

    cin >> N >> M;
    init();

    for (int i = 0; i < M; i++)
    {
        int l, r;
        cin >> l >> r;

        for (int i = l + 1; i <= r;)
        {
            unionSet(i, i - 1);

            i = rw[findRoot(i)] + 1;
        }
    }

    int ans = 0;
    for (int u = 1; u <= N;)
    {
        ans++;
        u = rw[findRoot(u)] + 1;
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
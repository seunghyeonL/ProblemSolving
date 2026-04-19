#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;
int N, K;
// vis[0][x] : 짝수 시간에 x에 도달하는 최소시간
// vid[1][x] : 홀수 시간에 x에 도달하는 최소시간
// 더 이후에 같은 지점에 도달하는 경우는 +1, -1왕복으로 처리할 수 있기 때문에 고려하지 않아도 된다.
int vis[2][500001];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < 2; i++)
        fill(vis[i], vis[i] + 500001, INF);

    queue<pair<int, int>> q;
    vis[0][N] = 0;
    q.emplace(N, 0);

    while (!q.empty())
    {
        auto [cx, ct] = q.front();
        q.pop();

        // cout << cx << ' ' << ct << ' ' << K + ct * (ct + 1) / 2 << '\n';

        for (int nx : {cx - 1, cx + 1, 2 * cx})
        {
            int nt = ct + 1;

            if (nx >= 0 && nx <= 500000 && vis[nt % 2][nx] == INF)
            {
                vis[nt % 2][nx] = nt;
                q.emplace(nx, nt);
            }
        }
    }

    int bt = 0;
    int answer = bt;
    int bx = K + bt * (bt + 1) / 2;
    bool found = false;
    while (bx <= 500000)
    {
        if (vis[bt % 2][bx] <= bt)
        {
            found = true;
            break;
        }
        bt++;
        bx = K + bt * (bt + 1) / 2;
    }

    cout << (found ? bt : -1) << '\n';

    // inputFileStream.close();
    return 0;
}
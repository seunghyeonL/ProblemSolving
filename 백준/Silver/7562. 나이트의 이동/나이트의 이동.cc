#include <bits/stdc++.h>
using namespace std;

const int LMX = 300;
int L;
int board[LMX][LMX];
int vis[LMX][LMX];

bool is_valid(int x, int y)
{
    return x >= 0 && x < L && y >= 0 && y < L;
}

vector<pair<int, int>> moves{
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
};

void solve()
{
    cin >> L;
    int sx, sy, tx, ty;

    cin >> sx >> sy >> tx >> ty;

    queue<pair<int, int>> q;

    for (int i = 0; i < L; i++)
        for (int j = 0; j < L; j++)
            vis[i][j] = -1;

    vis[sx][sy] = 0;
    q.emplace(sx, sy);

    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();

        if (cx == tx && cy == ty)
            break;

        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;

            if (is_valid(nx, ny) && vis[nx][ny] == -1)
            {
                vis[nx][ny] = vis[cx][cy] + 1;
                q.emplace(nx, ny);
            }
        }
    }

    cout << vis[tx][ty] << '\n';
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

    int T;
    cin >> T;

    while (T-- > 0)
        solve();

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int board[101][101]{};
bool visited[101][101]{};
vector<P> sw[101][101]{};

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     */

    int N, M;
    cin >> N >> M;

    // 1, 1 불켜기
    board[1][1] = 1;

    for (int i = 0; i < M; i++)
    {
        int x, y, tx, ty;
        cin >> x >> y >> tx >> ty;

        sw[x][y].emplace_back(tx, ty);
    }

    vector<P> moves{
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}};

    auto isValid = [&](int x, int y)
    {
        return x > 0 && x <= N && y > 0 && y <= N;
    };

    auto isConnected = [&](int x, int y) -> bool
    {
        bool res = false;

        for (auto [dx, dy] : moves)
        {
            int nx = x + dx;
            int ny = y + dy;
            if (isValid(nx, ny) && visited[nx][ny])
            {
                res = true;
                break;
            }
        }

        return res;
    };

    int res = 1;
    queue<P> q;
    q.emplace(1, 1);
    visited[1][1] = true;

    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();

        for (auto [sx, sy] : sw[cx][cy])
        {
            if (board[sx][sy] == 0)
            {
                board[sx][sy] = 1;
                res++;
            }

            if (!visited[sx][sy] && isConnected(sx, sy))
            {
                q.emplace(sx, sy);
                visited[sx][sy] = true;
            }
        }

        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;

            if (isValid(nx, ny) && !visited[nx][ny] && board[nx][ny] == 1)
            {
                q.emplace(nx, ny);
                visited[nx][ny] = true;
            }
        }
    }

    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= N; j++)
    //         cout << board[i][j] << ' ';

    //     cout << '\n';
    // }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}

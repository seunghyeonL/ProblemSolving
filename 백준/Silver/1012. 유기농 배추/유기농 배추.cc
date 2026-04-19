#include <bits/stdc++.h>
using namespace std;

#define first x
#define second y

void solve()
{
    using P = pair<int, int>;
    int M, N, K;
    cin >> M >> N >> K;

    vector<vector<int>> board(N, vector<int>(M));
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> y >> x;

        board[x][y] = 1;
    }

    auto isValid = [&](int x, int y)
    {
        return x >= 0 && x < N && y >= 0 && y < M;
    };

    vector<P> moves{
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };

    vector<vector<bool>> visited(N, vector<bool>(M));

    queue<P> q;

    auto bfs = [&](int sx, int sy)
    {
        q.emplace(sx, sy);
        visited[sx][sy] = true;

        while (!q.empty())
        {
            auto [cx, cy] = q.front();
            q.pop();

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
    };

    int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j] && board[i][j] == 1)
            {
                res++;
                bfs(i, j);
            }
        }
    }

    cout << res << '\n';
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

    for (int i = 0; i < T; i++)
    {
        solve();
    }

    // inputFileStream.close();
    return 0;
}
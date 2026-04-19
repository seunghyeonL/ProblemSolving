#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    using P = pair<int, int>;
    int N, M;
    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    auto isValid = [&](int x, int y)
    {
        return x >= 0 && x < N && y >= 0 && y < M;
    };

    vector<P> moves{
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}};

    vector<vector<bool>> isIce(N, vector<bool>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            isIce[i][j] = board[i][j] > 0;

    auto proceed = [&]()
    {
        vector<P> melted;

        for (int cx = 0; cx < N; cx++)
        {
            for (int cy = 0; cy < M; cy++)
            {
                if (board[cx][cy] == 0)
                    continue;

                for (auto [dx, dy] : moves)
                {
                    if (board[cx][cy] == 0)
                        break;

                    int nx = cx + dx;
                    int ny = cy + dy;

                    if (isValid(nx, ny) && board[nx][ny] == 0 && !isIce[nx][ny])
                    {
                        board[cx][cy]--;
                    }
                }

                if (board[cx][cy] == 0)
                    melted.emplace_back(cx, cy);
            }
        }

        for (auto [x, y] : melted)
        {
            isIce[x][y] = false;
        }
    };

    vector<vector<bool>> visited(N, vector<bool>(M));

    queue<P> q;

    auto resetVisited = [&]()
    {
        for (auto &line : visited)
        {
            fill(line.begin(), line.end(), false);
        }
    };

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

                if (isValid(nx, ny) && isIce[nx][ny] && !visited[nx][ny])
                {
                    q.emplace(nx, ny);
                    visited[nx][ny] = true;
                }
            }
        }
    };

    for (int t = 0;; t++)
    {
        int cnt = 0;
        for (int x = 1; x < N - 1; x++)
            for (int y = 1; y < M - 1; y++)
            {
                if (visited[x][y] || !isIce[x][y])
                    continue;

                cnt++;
                bfs(x, y);
            }

        if (cnt >= 2)
        {
            cout << t << '\n';
            break;
        }
        
        if (cnt == 0)
        {
            cout << 0 << '\n';
            break;
        }

        resetVisited();
        proceed();
    }

    // inputFileStream.close();
    return 0;
}
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
    int N;
    cin >> N;

    vector<string> board(N);
    for (int i = 0; i < N; i++)
        cin >> board[i];

    auto isValid = [&](int x, int y)
    {
        return x >= 0 && x < N && y >= 0 && y < N;
    };

    vector<P> moves{
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };

    vector<vector<bool>> visited(N, vector<bool>(N));

    auto resetVisited = [&]()
    {
        for (auto &line : visited)
        {
            fill(line.begin(), line.end(), false);
        }
    };

    queue<P> q;

    auto rgbBfs = [&](int sx, int sy)
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

                if (isValid(nx, ny) && !visited[nx][ny] && board[cx][cy] == board[nx][ny])
                {
                    q.emplace(nx, ny);
                    visited[nx][ny] = true;
                }
            }
        }
    };

    auto isSameAtRb = [](char c1, char c2)
    {
        if (c1 == c2)
            return true;
        else if (c1 == 'R' && c2 == 'G' || c1 == 'G' && c2 == 'R')
            return true;

        return false;
    };

    auto rbBfs = [&](int sx, int sy)
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

                if (isValid(nx, ny) && !visited[nx][ny] && isSameAtRb(board[cx][cy], board[nx][ny]))
                {
                    q.emplace(nx, ny);
                    visited[nx][ny] = true;
                }
            }
        }
    };

    int rgbRes = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                rgbBfs(i, j);
                rgbRes++;
            }
        }

    resetVisited();

    int rbRes = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                rbBfs(i, j);
                rbRes++;
            }
        }

    cout << rgbRes << ' ' << rbRes << '\n';

    // inputFileStream.close();
    return 0;
}
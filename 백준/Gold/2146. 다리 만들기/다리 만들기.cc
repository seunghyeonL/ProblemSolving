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

    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    auto isValid = [&](int x, int y)
    {
        return x >= 0 && x < N && y >= 0 && y < N;
    };

    vector<P> moves{
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}};

    vector<vector<int>> landType(N, vector<int>(N));

    auto setLandType = [&](int sx, int sy, int lt)
    {
        queue<P> q;
        q.emplace(sx, sy);
        landType[sx][sy] = lt;

        while (!q.empty())
        {
            auto [cx, cy] = q.front();
            q.pop();

            for (auto [dx, dy] : moves)
            {
                int nx = cx + dx;
                int ny = cy + dy;

                if (isValid(nx, ny) && landType[nx][ny] == 0 && board[nx][ny] == 1)
                {
                    q.emplace(nx, ny);
                    landType[nx][ny] = lt;
                }
            }
        }
    };

    int maxLt{};
    {
        int lt = 1;
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
            {
                if (landType[x][y] > 0 || board[x][y] == 0)
                    continue;

                setLandType(x, y, lt++);
            }
        }
        maxLt = lt - 1;
    }

    vector<vector<int>> dist(N, vector<int>(N, -1));
    auto resetDist = [&]()
    {
        for (auto &line : dist)
        {
            fill(line.begin(), line.end(), -1);
        }
    };

    auto getMinDist = [&](int lt)
    {
        resetDist();
        queue<P> q;
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
            {
                if (landType[x][y] == lt)
                {
                    q.emplace(x, y);
                    dist[x][y] = 0;
                }
            }
        }

        int res = 0;
        while (!q.empty())
        {
            auto [cx, cy] = q.front();
            q.pop();

            if (landType[cx][cy] > 0 && landType[cx][cy] != lt)
            {
                res = dist[cx][cy] - 1;
                break;
            }

            for (auto [dx, dy] : moves)
            {
                int nx = cx + dx;
                int ny = cy + dy;

                if (isValid(nx, ny) && landType[nx][ny] != lt && dist[nx][ny] == -1)
                {
                    q.emplace(nx, ny);
                    dist[nx][ny] = dist[cx][cy] + 1;
                }
            }
        }
        
        return res;
    };

    int res = 2 * N;
    for (int lt = 1; lt <= maxLt; lt++)
    {
        res = min(res, getMinDist(lt));
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
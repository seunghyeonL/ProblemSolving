#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        불 Dist, 지훈 Dist를 먼저 만들어 주고
        queue에 불을 먼저 넣고 지훈을 넣어서
        불이 번진곳으로는 못가는 방식으로 판별
    */

    using P = pair<int, int>;        // x, y
    using T = tuple<bool, int, int>; // isFire, x, y

    int R, C;
    cin >> R >> C;
    const int INF = 1e9;

    vector<string> maze(R);

    for (int i = 0; i < R; i++)
    {
        cin >> maze[i];
    }

    auto isValid = [&](int x, int y)
    {
        return x >= 0 && x < R && y >= 0 && y < C;
    };

    auto isEdge = [&](int x, int y)
    {
        return x == 0 || x == R - 1 || y == 0 || y == C - 1;
    };

    vector<P> moves{
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}};

    vector<vector<int>> fDist(R, vector<int>(C, INF));
    vector<vector<int>> jDist(R, vector<int>(C, INF));

    queue<T> q;

    vector<P> firepos;
    P jpos;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (maze[i][j] == 'F')
            {
                firepos.emplace_back(i, j);
            }

            if (maze[i][j] == 'J')
            {
                jpos = {i, j};
            }
        }
    }

    for (auto [x, y] : firepos)
    {
        q.emplace(true, x, y);
        fDist[x][y] = 0;
    }
    q.emplace(false, jpos.first, jpos.second);
    jDist[jpos.first][jpos.second] = 0;

    int res = 0;

    while (!q.empty())
    {
        auto [isFire, cx, cy] = q.front();
        q.pop();

        if (!isFire && isEdge(cx, cy))
        {
            res = jDist[cx][cy] + 1;
            break;
        }

        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;

            if (!isValid(nx, ny) || maze[nx][ny] == '#')
                continue;

            if (isFire && fDist[nx][ny] == INF)
            {
                q.emplace(true, nx, ny);
                fDist[nx][ny] = fDist[cx][cy] + 1;
            }
            else if (!isFire && jDist[nx][ny] == INF && jDist[cx][cy] + 1 < fDist[nx][ny])
            {
                q.emplace(false, nx, ny);
                jDist[nx][ny] = jDist[cx][cy] + 1;
            }
        }
    }

    if (res == 0)
        cout << "IMPOSSIBLE" << '\n';
    else
        cout << res << '\n';

    // inputFileStream.close();
    return 0;
}


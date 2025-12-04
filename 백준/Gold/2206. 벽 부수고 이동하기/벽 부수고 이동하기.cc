#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;
int N, M;
char board[MX + 1][MX + 1];
// dist[x][y][b] : {1, 1} -> {x, y} 거리
// b : 벽 부숴는지 여부
int dist[MX + 1][MX + 1][2];

bool is_valid(int x, int y)
{
    return x > 0 && x <= N && y > 0 && y <= M;
}

vector<pair<int, int>> moves{
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> board[i][j];

    queue<tuple<int, int, int>> q;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            dist[i][j][0] = -1;
            dist[i][j][1] = -1;
        }

    dist[1][1][0] = 1;
    q.emplace(1, 1, 0);

    int ans = -1;

    while (!q.empty())
    {
        auto [cx, cy, b] = q.front();
        q.pop();

        if (cx == N && cy == M)
        {
            ans = dist[cx][cy][b];
            break;
        }

        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;

            if (!is_valid(nx, ny))
                continue;

            if (board[nx][ny] == '1' && b == 0 && dist[nx][ny][1] == -1)
            {
                dist[nx][ny][1] = dist[cx][cy][0] + 1;
                q.emplace(nx, ny, 1);
            }

            if (board[nx][ny] == '0' && dist[nx][ny][b] == -1)
            {
                dist[nx][ny][b] = dist[cx][cy][b] + 1;
                q.emplace(nx, ny, b);
            }
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
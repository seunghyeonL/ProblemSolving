#include <bits/stdc++.h>
using namespace std;

using T = tuple<int, int, int>;
const int MX = 100;
int N, M, H;
int board[MX][MX][MX];
int vis[MX][MX][MX];

bool is_valid(int x, int y, int z)
{
    return x >= 0 && x < N && y >= 0 && y < M && z >= 0 && z < H;
}

vector<T> moves{
    {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1},
};

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

    cin >> M >> N >> H;

    vector<T> starts;

    for (int z = 0; z < H; z++)
        for (int x = 0; x < N; x++)
            for (int y = 0; y < M; y++)
            {
                int n;
                cin >> n;
                board[x][y][z] = n;

                if (n == 1)
                    starts.emplace_back(x, y, z);
            }

    for (int z = 0; z < H; z++)
        for (int x = 0; x < N; x++)
            for (int y = 0; y < M; y++)
                vis[x][y][z] = -1;

    queue<T> q;

    for (auto [sx, sy, sz] : starts)
    {
        vis[sx][sy][sz] = 0;
        q.emplace(sx, sy, sz);
    }

    while (!q.empty())
    {
        auto [cx, cy, cz] = q.front();
        q.pop();

        for (auto [dx, dy, dz] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;
            int nz = cz + dz;

            if (is_valid(nx, ny, nz) && board[nx][ny][nz] == 0 &&
                vis[nx][ny][nz] == -1)
            {
                vis[nx][ny][nz] = vis[cx][cy][cz] + 1;
                q.emplace(nx, ny, nz);
            }
        }
    }

    bool end_flag = false;
    int ans = 0;
    for (int z = 0; z < H && !end_flag; z++)
        for (int x = 0; x < N && !end_flag; x++)
            for (int y = 0; y < M; y++)
            {
                if (vis[x][y][z] == -1)
                {
                    if (board[x][y][z] == 0)
                    {
                        ans = -1;
                        end_flag = true;
                        break;
                    }

                    continue;
                }

                ans = max(ans, vis[x][y][z]);
            }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
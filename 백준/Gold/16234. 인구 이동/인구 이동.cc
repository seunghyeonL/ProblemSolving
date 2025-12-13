#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;

const int NMX = 50;
int N, L, R;

int arr[50][50];
bool vis[50][50];

vector<P> moves{
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

bool is_valid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}

void reset_vis()
{
    memset(vis, false, sizeof(vis));
}

bool p_move()
{
    reset_vis();

    vector<vector<P>> clusters;

    queue<P> q;

    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
        {
            if (vis[x][y])
                continue;

            q.emplace(x, y);
            vis[x][y] = true;

            vector<P> cluster;

            while (!q.empty())
            {
                auto [cx, cy] = q.front();
                q.pop();

                cluster.emplace_back(cx, cy);

                for (auto [dx, dy] : moves)
                {
                    int nx = cx + dx;
                    int ny = cy + dy;

                    int diff = abs(arr[nx][ny] - arr[cx][cy]);

                    if (is_valid(nx, ny) && !vis[nx][ny] && diff >= L &&
                        diff <= R)
                    {
                        q.emplace(nx, ny);
                        vis[nx][ny] = true;
                    }
                }
            }

            if (cluster.size() >= 2)
            {
                clusters.push_back(cluster);
            }
        }

    if (clusters.empty())
        return false;

    for (const auto &cluster : clusters)
    {
        int avg = 0;
        for (auto [x, y] : cluster)
        {
            avg += arr[x][y];
        }

        avg /= cluster.size();

        for (auto [x, y] : cluster)
        {
            arr[x][y] = avg;
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> L >> R;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    int ans = 0;
    while (p_move())
        ans++;

    cout << ans << '\n';

    // inputFileStream.close();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int NMX = 25;
int N;
char board[NMX][NMX];
bool vis[NMX][NMX];

bool is_valid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}

vector<pair<int, int>> moves{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(int sx, int sy)
{
    queue<pair<int, int>> q;

    vis[sx][sy] = true;
    q.emplace(sx, sy);

    int ret = 0;

    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();

        ret++;

        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;

            if (is_valid(nx, ny) && !vis[nx][ny] && board[nx][ny] == '1')
            {
                vis[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }

    return ret;
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

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (vis[i][j] || board[i][j] == '0')
                continue;

            ans.push_back(bfs(i, j));
        }
    }

    sort(ans.begin(), ans.end());
    
    cout << ans.size() << '\n';
    for (int el : ans)
    {
        cout << el << '\n';
    }

    // inputFileStream.close();
    return 0;
}
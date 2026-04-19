#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
const int NMX = 8;
int N, M;
int board[NMX][NMX];
bool vis[NMX][NMX];

vector<P> virus;
vector<P> zeros;

void reset_vis()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            vis[i][j] = false;
}

bool is_valid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

vector<P> moves{
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

void propagate(const set<P> &walls)
{
    reset_vis();

    queue<P> q;
    for (auto [vx, vy] : virus)
    {
        vis[vx][vy] = true;
        q.emplace(vx, vy);
    }

    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();

        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;

            if (!is_valid(nx, ny) || board[nx][ny] == 1 ||
                walls.count({nx, ny}) || vis[nx][ny])
                continue;

            vis[nx][ny] = true;
            q.emplace(nx, ny);
        }
    }
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        벽을 세울 수 있는 모든 조합 -> O( (N * M)^3 ) = O(2^18) < O(10^6)

     */

    // ifstream inputFileStream("input.txt");

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
            {
                zeros.emplace_back(i, j);
            }
            else if (board[i][j] == 2)
            {
                virus.emplace_back(i, j);
            }
        }
    }

    vector<bool> mask(zeros.size());
    fill(mask.begin(), mask.begin() + 3, true);

    int ans = 0;

    do
    {
        set<P> walls;
        for (int i = 0; i < mask.size(); i++)
        {
            if (mask[i])
                walls.insert(zeros[i]);
        }

        propagate(walls);

        int cdd = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] == 0 && !vis[i][j] && !walls.count({i, j}))
                    cdd++;
            }

        ans = max(ans, cdd);

    } while (prev_permutation(mask.begin(), mask.end()));

    cout << ans;

    // inputFileStream.close();
    return 0;
}
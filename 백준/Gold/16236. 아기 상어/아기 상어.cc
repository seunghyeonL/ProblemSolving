#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1'000'000'000;
constexpr int NMX = 20;
int N;
array<array<int, NMX>, NMX> board{};
array<array<int, NMX>, NMX> dist{};

int csz = 2;
int sz_up_cnt = 0;
pair<int, int> cp;

vector<pair<int, int>> moves{
    {-1, 0}, // U
    {0, -1}, // L
    {0, 1},  // R
    {1, 0},  // D
};

bool is_valid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}

void init_dist()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dist[i][j] = INF;
}

int simulate()
{
    init_dist();

    auto [sx, sy] = cp;

    queue<pair<int, int>> q;
    dist[sx][sy] = 0;
    q.emplace(sx, sy);

    int min_dist = INF;

    vector<pair<int, int>> cand;
    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();

        if (dist[cx][cy] > min_dist)
            break;

        if (board[cx][cy] > 0 && board[cx][cy] < csz)
        {
            if (min_dist > dist[cx][cy])
                min_dist = dist[cx][cy];

            cand.emplace_back(cx, cy);
            continue;
        }

        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;

            if (!is_valid(nx, ny) || board[nx][ny] > csz || dist[nx][ny] < INF)
                continue;

            dist[nx][ny] = dist[cx][cy] + 1;
            q.emplace(nx, ny);
        }
    }

    if (cand.empty())
        return 0;
    else
    {
        sort(cand.begin(), cand.end());

        // 먹기
        auto [tx, ty] = cand[0];
        cp = {tx, ty};

        if (++sz_up_cnt == csz)
        {
            csz++;
            sz_up_cnt = 0;
        }

        board[tx][ty] = 0;

        return min_dist;
    }
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                board[i][j] = 0;
                cp = {i, j};
            }
        }

    int ans = 0;

    while (true)
    {
        int t = simulate();

        if (t == 0)
            break;

        ans += t;
    }

    cout << ans << '\n';

    // inputFileStream.close();
    return 0;
}

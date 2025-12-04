#include <bits/stdc++.h>
using namespace std;    

const int MX = 10;
int N, M;
int board[MX][MX];
vector<tuple<int, int, int>> E; // w, u, v
int uf[MX * MX];

int get_node_num(int x, int y)
{
    return M * x + y;
}

int find_root(int u)
{
    if (uf[u] < 0)
        return u;
    return uf[u] = find_root(uf[u]);
}

bool union_set(int u, int v)
{
    u = find_root(u);
    v = find_root(v);

    if (u == v)
        return false;

    // u -> v
    if (uf[u] < uf[v])
        swap(u, v);

    uf[v] = uf[u] + uf[v];
    uf[u] = v;

    return true;
}

bool is_valid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < M;
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

    /*
     */

    cin >> N >> M;
    fill(uf, uf + N * M, -1);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    for (int x = 0; x < N; x++)
        for (int y = 0; y < M; y++)
        {
            if (!board[x][y])
                continue;

            int u = get_node_num(x, y);

            for (auto [dx, dy] : moves)
            {
                int adj_x = x + dx;
                int adj_y = y + dy;

                if (is_valid(adj_x, adj_y) && board[adj_x][adj_y])
                {
                    int v = get_node_num(adj_x, adj_y);
                    union_set(u, v);
                }
            }
        }

    for (int x = 0; x < N; x++)
    {
        int u = -1;
        int uy = -1;
        for (int y = 0; y < M; y++)
        {
            if (board[x][y])
            {
                int v = find_root(get_node_num(x, y));

                if (u < 0)
                {
                    u = v;
                    uy = y;
                    continue;
                }

                if (u == v)
                {
                    uy = y;
                    continue;
                }

                if (y - uy - 1 < 2)
                {
                    u = v;
                    uy = y;
                    continue;
                }

                // cout << uy << ' ' << y << '\n';
                E.emplace_back(y - uy - 1, u, v);
                u = v;
                uy = y;
            }
        }
    }

    for (int y = 0; y < M; y++)
    {
        int u = -1;
        int ux = -1;
        for (int x = 0; x < N; x++)
        {
            if (board[x][y])
            {
                int v = find_root(get_node_num(x, y));

                if (u < 0)
                {
                    u = v;
                    ux = x;
                    continue;
                }

                if (u == v)
                {
                    ux = x;
                    continue;
                }

                if (x - ux - 1 < 2)
                {
                    u = v;
                    ux = x;
                    continue;
                }

                // cout << ux << ' ' << x << '\n';
                E.emplace_back(x - ux - 1, u, v);
                u = v;
                ux = x;
            }
        }
    }

    sort(E.begin(), E.end());

    int island_num = 0;
    for (int x = 0; x < N; x++)
        for (int y = 0; y < M; y++)
        {
            if (uf[get_node_num(x, y)] < 0 && board[x][y])
                island_num++;
        }

    int ans = 0;
    int cnt = 0;
    for (auto [c, u, v] : E)
    {
        if (cnt == island_num - 1)
            break;

        if (union_set(u, v))
        {
            ans += c;
            cnt++;
        }
    }

    if (cnt < island_num - 1)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
int N, M;
int r, c, d;
int board[51][51];
int answer = 0;

bool isValid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

P moves[4]{
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}};

bool noNextNonCleanArea(int x, int y)
{
    bool res = true;
    for (auto [dx, dy] : moves)
    {
        int nx = x + dx;
        int ny = y + dy;

        if (isValid(nx, ny) && board[nx][ny] == 0)
            res = false;
    }

    return res;
}

void clean(int x, int y)
{
    if (board[x][y] == 0)
    {
        board[x][y] = 2;
        answer++;
    }
}

void run(int cx, int cy, int cd)
{
    clean(cx, cy);

    if (noNextNonCleanArea(cx, cy))
    {
        auto [dx, dy] = moves[(cd + 2) % 4];
        int nx = cx + dx;
        int ny = cy + dy;

        if (isValid(nx, ny) && board[nx][ny] != 1)
            run(nx, ny, cd);

        return;
    }

    for (int i = 1; i <= 4; i++)
    {
        int nd = (4 + cd - i) % 4;
        auto [dx, dy] = moves[nd];
        int nx = cx + dx;
        int ny = cy + dy;

        if (isValid(nx, ny) && board[nx][ny] == 0)
        {
            run(nx, ny, nd);
            break;
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
     */
    cin >> N >> M;
    cin >> r >> c >> d;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    run(r, c, d);

    cout << answer << '\n';
    // inputFileStream.close();
    return 0;
}
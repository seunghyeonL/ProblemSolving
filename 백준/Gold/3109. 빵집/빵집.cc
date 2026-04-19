#include <bits/stdc++.h>
using namespace std;

const int MX = 10000;
int R, C;
char board[MX][MX];
bool used[MX][MX];

bool is_valid(int x, int y)
{
    return x >= 0 && x < R && y >= 0 && y < C;
}

vector<pair<int, int>> moves{
    {-1, 1},
    {0, 1},
    {1, 1},
};

void rec(int cx, int cy, bool &ok, int &ans)
{
    if (cy == C - 1)
    {
        ans++;
        ok = true;
        return;
    }

    for (auto [dx, dy] : moves)
    {
        int nx = cx + dx;
        int ny = cy + dy;

        if (is_valid(nx, ny) && board[nx][ny] == '.' && !used[nx][ny])
        {
            used[nx][ny] = true;
            rec(nx, ny, ok, ans);

            if (ok)
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

    // ifstream inputFileStream("input.txt");

    cin >> R >> C;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> board[i][j];

    int ans = 0;
    for (int i = 0; i < R; i++)
    {
        bool ok = false;
        used[i][0] = true;
        rec(i, 0, ok, ans);
    }

    cout << ans << '\n';

    // inputFileStream.close();
    return 0;
}
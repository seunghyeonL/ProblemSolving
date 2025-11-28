#include <bits/stdc++.h>
using namespace std;

const int LMT = 1500;
const int L = 4 * LMT; // ST 가로세로 길이(넉넉하게)
int N, M;
int board[LMT + 1][LMT + 1];

int ST[L][L];

void init_ST_y(int cv_x, int cv_y, int sy, int ey, int x)
{
    if (sy == ey)
    {
        ST[cv_x][cv_y] = board[x][sy];
        return;
    }

    int my = (sy + ey) / 2;
    init_ST_y(cv_x, cv_y * 2, sy, my, x);
    init_ST_y(cv_x, cv_y * 2 + 1, my + 1, ey, x);

    ST[cv_x][cv_y] = max(ST[cv_x][cv_y * 2], ST[cv_x][cv_y * 2 + 1]);
}

void pull_y(int cv_x, int cv_y, int sy, int ey)
{
    if (sy == ey)
    {
        ST[cv_x][cv_y] = max(ST[cv_x * 2][cv_y], ST[cv_x * 2 + 1][cv_y]);
        return;
    }

    int my = (sy + ey) / 2;

    pull_y(cv_x, cv_y * 2, sy, my);
    pull_y(cv_x, cv_y * 2 + 1, my + 1, ey);

    ST[cv_x][cv_y] = max(ST[cv_x][cv_y * 2], ST[cv_x][cv_y * 2 + 1]);
}

void init_ST(int cv_x, int sx, int ex)
{
    if (sx == ex)
    {
        init_ST_y(cv_x, 1, 0, LMT, sx);
        return;
    }

    int mx = (sx + ex) / 2;

    init_ST(cv_x * 2, sx, mx);
    init_ST(cv_x * 2 + 1, mx + 1, ex);

    pull_y(cv_x, 1, 0, LMT);
}

// void update_y(int cv_x, int cv_y, int sy, int ey, int y, int val)
// {
//     if (y < sy || y > ey)
//         return;

//     ST[cv_x][cv_y] = max(ST[cv_x][cv_y], val);

//     if (sy == ey)
//         return;

//     int my = (sy + ey) / 2;

//     update_y(cv_x, cv_y * 2, sy, my, y, val);
//     update_y(cv_x, cv_y * 2 + 1, my + 1, ey, y, val);
// }

// void update(int cv_x, int sx, int ex, int x, int y, int val)
// {
//     if (x < sx || x > ex)
//         return;

//     update_y(cv_x, 1, 0, LMT, y, val);

//     if (sx == ex)
//         return;

//     int mx = (sx + ex) / 2;

//     update(cv_x * 2, sx, mx, x, y, val);
//     update(cv_x * 2 + 1, mx + 1, ex, x, y, val);
// }

int query_y(int cv_x, int cv_y, int sy, int ey, int ly, int ry)
{
    if (ey < ly || ry < sy)
        return 0;

    if (ly <= sy && ey <= ry)
        return ST[cv_x][cv_y];

    int my = (sy + ey) / 2;
    return max(query_y(cv_x, cv_y * 2, sy, my, ly, ry),
               query_y(cv_x, cv_y * 2 + 1, my + 1, ey, ly, ry));
}

int query(int cv_x, int sx, int ex, int lx, int rx, int ly, int ry)
{
    if (ex < lx || rx < sx)
        return 0;

    if (lx <= sx && ex <= rx)
        return query_y(cv_x, 1, 0, LMT, ly, ry);

    int mx = (sx + ex) / 2;
    return max(query(cv_x * 2, sx, mx, lx, rx, ly, ry),
               query(cv_x * 2 + 1, mx + 1, ex, lx, rx, ly, ry));
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

    cin >> N >> M;

    // 2d imos
    for (int i = 0; i < N; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        board[x1][y1] += 1;
        board[x1][y2] -= 1;
        board[x2][y1] -= 1;
        board[x2][y2] += 1;
    }

    for (int x = 0; x <= LMT; x++)
        for (int y = 1; y <= LMT; y++)
            board[x][y] += board[x][y - 1];

    for (int y = 0; y <= LMT; y++)
        for (int x = 1; x <= LMT; x++)
            board[x][y] += board[x - 1][y];

    init_ST(1, 0, LMT);

    for (int i = 0; i < M; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << query(1, 0, LMT, x1, x2 - 1, y1, y2 - 1) << '\n';
    }

    // for (int x = 8; x >= 0; x--)
    // {
    //     for (int y = 0; y <= 8; y++)
    //     {
    //         cout << board[x][y] << ' ';
    //     }
    //     cout << '\n';
    // }

    // inputFileStream.close();
    return 0;
}
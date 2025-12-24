#include <bits/stdc++.h>
using namespace std;

const int KMX = 7;
int K;
int ex, ey;
int tile_num;

int board[1 << KMX][1 << KMX];

// sx, sy : 왼쪽 위 시작점 좌표
// d : 비울 위치 (0 1)
//             (2 3)
// sz : 정사각형 크기

void DnC2(int sx, int sy, int sz, int d)
{
    if (sz == 2)
    {
        ++tile_num;
        for (int i = 0; i <= 1; i++)
            for (int j = 0; j <= 1; j++)
            {
                if (2 * i + j == d)
                    continue;

                board[sx + i][sy + j] = tile_num;
            }

        return;
    }

    if (d != 0)
        DnC2(sx, sy, sz / 2, 3);

    if (d != 1)
        DnC2(sx, sy + sz / 2, sz / 2, 2);

    if (d != 2)
        DnC2(sx + sz / 2, sy, sz / 2, 1);

    if (d != 3)
        DnC2(sx + sz / 2, sy + sz / 2, sz / 2, 0);

    DnC2(sx + sz / 4, sy + sz / 4, sz / 2, d);
}

void DnC1(int sx, int sy, int sz)
{
    // 비울 위치
    int d = (ex - sx) / (sz / 2) * 2 + (ey - sy) / (sz / 2);

    if (sz == 2)
    {
        ++tile_num;
        for (int i = 0; i <= 1; i++)
            for (int j = 0; j <= 1; j++)
            {
                if (2 * i + j == d)
                    continue;

                board[sx + i][sy + j] = tile_num;
            }

        return;
    }

    DnC2(sx, sy, sz, d);

    DnC1(sx + (d == 2 || d == 3 ? sz / 2 : 0),
         sy + (d == 1 || d == 3 ? sz / 2 : 0), sz / 2);
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> K;
    cin >> ey >> ex;
    board[--ex][--ey] = -1;

    int sz = 1 << K;

    if ((sz * sz - 1) % 3 != 0)
    {
        cout << -1 << '\n';
        return 0;
    }

    if ((sz * sz - 1) / 3 > 19000)
    {
        cout << -1 << '\n';
        return 0;
    }

    DnC1(0, 0, sz);

    for (int i = sz - 1; i >= 0; i--)
    {
        for (int j = 0; j < sz; j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
using P = pair<int, int>;
const int NMX = 10;
int N, M;
string board[NMX + 1];
P cr;
P cb;

vector<P> moves{
    {0, 1},  // R
    {1, 0},  // D
    {0, -1}, // L
    {-1, 0}  // U
};
bool moveBall(P &pos, int dir, char color)
{
    bool arriveHall = false;
    auto &[cx, cy] = pos;
    auto [dx, dy] = moves[dir];

    while (true)
    {
        int nx = cx + dx;
        int ny = cy + dy;

        if (board[nx][ny] == '.')
        {
            board[cx][cy] = '.';
            cx = nx;
            cy = ny;
            board[cx][cy] = color;
        }
        else if (board[nx][ny] == 'O')
        {
            board[cx][cy] = '.';
            cx = nx;
            cy = ny;
            arriveHall = true;
            break;
        }
        else
        {
            break;
        }
    }

    return arriveHall;
}

// 0: 끝나지 않음, 1: 빨간공 구멍 도착, 2: 파란공 구멍 도착
int leanBoard(int dir)
{
    auto [rx, ry] = cr;
    auto [bx, by] = cb;

    bool rOut = false;
    bool bOut = false;
    if (dir == 0) // R
    {
        if (ry < by)
        {
            bOut = moveBall(cb, dir, 'B');
            rOut = moveBall(cr, dir, 'R');
        }
        else
        {
            rOut = moveBall(cr, dir, 'R');
            bOut = moveBall(cb, dir, 'B');
        }
    }
    else if (dir == 1) // D
    {
        if (rx < bx)
        {
            bOut = moveBall(cb, dir, 'B');
            rOut = moveBall(cr, dir, 'R');
        }
        else
        {
            rOut = moveBall(cr, dir, 'R');
            bOut = moveBall(cb, dir, 'B');
        }
    }
    else if (dir == 2) // L
    {
        if (ry > by)
        {
            bOut = moveBall(cb, dir, 'B');
            rOut = moveBall(cr, dir, 'R');
        }
        else
        {
            rOut = moveBall(cr, dir, 'R');
            bOut = moveBall(cb, dir, 'B');
        }
    }
    else // U
    {
        if (rx > bx)
        {
            bOut = moveBall(cb, dir, 'B');
            rOut = moveBall(cr, dir, 'R');
        }
        else
        {
            rOut = moveBall(cr, dir, 'R');
            bOut = moveBall(cb, dir, 'B');
        }
    }

    if (bOut)
        return 2;

    if (rOut)
        return 1;

    return 0;
}

void solveRec(int cnt, int &answer)
{
    if (cnt >= answer)
    {
        return;
    }

    for (int dir = 0; dir < 4; dir++)
    {
        P pb = cb;
        P pr = cr;
        int leanRes = leanBoard(dir);

        if (leanRes == 0)
        {
            solveRec(cnt + 1, answer);
        }

        if (board[cb.x][cb.y] == 'B')
            board[cb.x][cb.y] = '.';

        if (board[cr.x][cr.y] == 'R')
            board[cr.x][cr.y] = '.';

        cb = pb;
        cr = pr;
        board[cb.x][cb.y] = 'B';
        board[cr.x][cr.y] = 'R';

        if (leanRes == 1)
        {
            answer = min(answer, cnt);
        }
    }
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
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 'R')
                cr = {i, j};
            else if (board[i][j] == 'B')
                cb = {i, j};
        }

    int answer = 11;
    solveRec(1, answer);
    cout << (answer == 11 ? -1 : answer) << '\n';

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
int N = 12;
int M = 6;
char board[6][12];
bool visited[6][12];
P moves[4]{
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}};

bool isValid(int x, int y)
{
    return x >= 0 && x < M && y >= 0 && y < N;
}

void resetVisited()
{
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            visited[i][j] = false;
}

void getSameEl(int cx, int cy, vector<P> &history)
{
    char c = board[cx][cy];
    visited[cx][cy] = true;
    history.emplace_back(cx, cy);

    for (auto [dx, dy] : moves)
    {
        int nx = cx + dx;
        int ny = cy + dy;

        if (isValid(nx, ny) && !visited[nx][ny] && c == board[nx][ny])
        {
            getSameEl(nx, ny, history);
        }
    }
}

bool destory()
{
    resetVisited();

    bool destroyed = false;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            vector<P> sameEl;
            if (!visited[i][j] && board[i][j] != '.')
            {
                getSameEl(i, j, sameEl);
            }

            if (sameEl.size() >= 4)
            {
                for (auto [x, y] : sameEl)
                {
                    board[x][y] = '.';
                }

                destroyed = true;
            }
        }
    }

    return destroyed;
}

// x 가로줄을 왼쪽으로 밀기
void pushBlocks(int x)
{
    int bottom = 0;
    int l = 0;
    int r = 0;

    while (bottom < N)
    {
        // '.'이 아닐때까지 l늘리기
        while (l < N && board[x][l] == '.')
        {
            l++;
        }

        r = l;

        // '.'이 나올때까지 r 늘리기
        while (r < N && board[x][r] != '.')
        {
            r++;
        }

        if (r == l)
            break;

        copy(board[x] + l, board[x] + r, board[x] + bottom);
        bottom += r - l;
        l = max(l, bottom);

        fill(board[x] + l, board[x] + r, '.');
    }
};

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        x, y 반대로 해서 입력받기
        그리고 가로줄을 뒤집기
     */

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[j][i];

    for (int i = 0; i < M; i++)
    {
        reverse(board[i], board[i] + N);
    }

    int cnt = 0;
    while (destory())
    {
        cnt++;
        for (int i = 0; i < M; i++)
        {
            pushBlocks(i);
        }

        // for (int i = 0; i < M; i++)
        // {
        //     for (int j = 0; j < N; j++)
        //         cout << board[i][j] << ' ';

        //     cout << '\n';
        // }
        // cout << '\n';
    }

    cout << cnt << '\n';

    // inputFileStream.close();
    return 0;
}


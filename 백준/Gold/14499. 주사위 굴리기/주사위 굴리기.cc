#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, K;
int board[21][21];
deque<int> row(4);
deque<int> col(4);

bool isValid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

void role(int &x, int &y, int op)
{
    if (op == 1)
    {
        if (!isValid(x, y + 1))
            return;

        y++;

        int f = row.front();
        row.pop_front();
        row.push_back(f);

        col[0] = row[0];
        if (board[x][y] == 0)
        {
            board[x][y] = col[2] = row[2];
        }
        else
        {
            col[2] = row[2] = board[x][y];
            board[x][y] = 0;
        }
        cout << row[0] << '\n';
    }
    else if (op == 2)
    {
        if (!isValid(x, y - 1))
            return;

        y--;

        int b = row.back();
        row.pop_back();
        row.push_front(b);

        col[0] = row[0];

        if (board[x][y] == 0)
        {
            board[x][y] = col[2] = row[2];
        }
        else
        {
            col[2] = row[2] = board[x][y];
            board[x][y] = 0;
        }
        cout << row[0] << '\n';
    }
    else if (op == 3)
    {
        if (!isValid(x - 1, y))
            return;

        x--;

        int b = col.back();
        col.pop_back();
        col.push_front(b);

        row[0] = col[0];

        if (board[x][y] == 0)
        {
            board[x][y] = row[2] = col[2];
        }
        else
        {
            row[2] = col[2] = board[x][y];
            board[x][y] = 0;
        }
        cout << col[0] << '\n';
    }
    else if (op == 4)
    {
        if (!isValid(x + 1, y))
            return;

        x++;

        int f = col.front();
        col.pop_front();
        col.push_back(f);

        row[0] = col[0];

        if (board[x][y] == 0)
        {
            board[x][y] = row[2] = col[2];
        }
        else
        {
            row[2] = col[2] = board[x][y];
            board[x][y] = 0;
        }

        cout << col[0] << '\n';
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
        주사위의 상태를 deque 두개로 표현
        각 deque의 idx 0이 윗면
        각 deque의 idx 2가 바닥
            6
            2
        6 4 1 3
            5

        오른쪽 굴리기
            4
            2
        4 1 3 6
            5
    */

    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    row[2] = col[2] = board[x][y];
    board[x][y] = 0;

    for (int i = 0; i < K; i++)
    {
        int op;
        cin >> op;
        role(x, y, op);
    }

    // inputFileStream.close();
    return 0;
}

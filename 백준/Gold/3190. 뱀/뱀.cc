#include <bits/stdc++.h>
using namespace std;

const int NMX = 100;
int N, K, L;
int board[NMX + 1][NMX + 1];
queue<pair<int, int>> commands;
vector<pair<int, int>> moves{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
deque<pair<int, int>> snake;
int dir;

bool isValid(int x, int y)
{
    return x >= 1 && x <= N && y >= 1 && y <= N;
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

    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;

        board[x][y] = 1;
    }

    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int t;
        char c;
        cin >> t >> c;
        commands.emplace(t, c);
    }

    int t = 0;
    snake.emplace_back(1, 1);
    dir = 0;
    board[1][1] = 2;

    while (true)
    {
        t++;

        auto [hx, hy] = snake.back();
        auto [dx, dy] = moves[dir];

        int nx = hx + dx;
        int ny = hy + dy;

        if (!isValid(nx, ny) || board[nx][ny] == 2)
            break;

        if (board[nx][ny] != 1)
        {
            auto [tx, ty] = snake.front();
            board[tx][ty] = 0;
            snake.pop_front();
        }

        board[nx][ny] = 2;
        snake.emplace_back(nx, ny);

        if (!commands.empty())
        {
            auto [ct, cd] = commands.front();
            if (ct == t)
            {
                commands.pop();
                if (cd == 'D')
                    dir = (dir + 1) % 4;
                else if (cd == 'L')
                    dir = (4 + dir - 1) % 4;
            }
        }

        // cout << t << '\n';
        // for (int i = 1; i <= N; i++)
        // {
        //     for (int j = 1; j <= N; j++)
        //         cout << board[i][j] << ' ';
        //     cout << '\n';
        // }
        // cout << '\n';
    }

    cout << t << '\n';

    // inputFileStream.close();
    return 0;
}

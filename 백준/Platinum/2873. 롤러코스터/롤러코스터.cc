#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;
int board[MX][MX];
int N, M;

enum Direction
{
    D,
    R,
    U,
    L
};

vector<char> dir{'D', 'R', 'U', 'L'};
vector<pair<int, int>> moves{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    if (N % 2 == 1)
    {
        int i = 0, d = R;
        while (i < N)
        {
            for (int j = 0; j < M - 1; j++)
                cout << dir[d];

            if (i == N - 1)
                break;

            cout << 'D';
            d = (d + 2) % 4;
            i++;
        }

        return 0;
    }

    if (M % 2 == 1)
    {
        int j = 0, d = D;
        while (j < M)
        {
            for (int i = 0; i < N - 1; i++)
                cout << dir[d];

            if (j == M - 1)
                break;

            cout << 'R';
            d = (d + 2) % 4;
            j++;
        }

        return 0;
    }

    // N, M이 짝수일때
    {
        // (x + y) % 2 == 1 인 좌표값중 최솟값을 안먹어야함
        int tx{}, ty{}, mn = 1010;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (mn > board[i][j] && (i + j) % 2 == 1)
                {
                    mn = board[i][j];
                    tx = i;
                    ty = j;
                }

        int i = 0, d1 = R, d2 = D;
        while (i < N)
        {
            if (i / 2 == tx / 2)
            {
                int j = 0;
                while (j < M)
                {
                    if (j == M - 1 && i % 2 == 1)
                        break;

                    auto [dx, dy] = moves[d2];
                    int nx = i + dx;
                    int ny = j + dy;

                    if (nx != tx || ny != ty)
                    {
                        i = nx;
                        j = ny;
                        cout << dir[d2];
                        d2 = (d2 + 2) % 4;
                    }

                    if (j == M - 1)
                        break;

                    j += 1;
                    cout << 'R';
                }
            }
            else
            {
                for (int j = 0; j < M - 1; j++)
                    cout << dir[d1];
            }

            if (i == N - 1)
                break;

            i += 1;
            cout << 'D';
            d1 = (d1 + 2) % 4;
        }
    }

    // inputFileStream.close();
    return 0;
}
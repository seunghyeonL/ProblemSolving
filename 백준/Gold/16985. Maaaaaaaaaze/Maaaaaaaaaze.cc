#include <bits/stdc++.h>
using namespace std;
using T = tuple<int, int, int>;
int INF = 1e9;
int res = INF;
// n번째 판, 회전이동 횟수, x, y
int board[5][4][5][5];
int maze[5][5][5];
int dist[5][5][5];
bool used[5];
queue<T> q;

vector<T> moves{{1, 0, 0},  {0, 1, 0},  {0, 0, 1},
                {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};

void resetDist()
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                dist[i][j][k] = -1;
}

bool isValid(int z, int x, int y)
{
    return z >= 0 && z < 5 && x >= 0 && x < 5 && y >= 0 && y < 5;
}

void resetQueue()
{
    while (!q.empty())
        q.pop();
}

void bfs()
{
    if (maze[0][0][0] != 1)
    {
        return;
    }

    resetDist();
    resetQueue();

    dist[0][0][0] = 0;
    q.emplace(0, 0, 0);

    while (!q.empty())
    {
        auto [cz, cx, cy] = q.front();
        q.pop();

        if (cz == 4 && cx == 4 && cy == 4)
        {
            res = min(res, dist[cz][cx][cy]);
            break;
        }

        for (auto [dz, dx, dy] : moves)
        {
            int nz = cz + dz;
            int nx = cx + dx;
            int ny = cy + dy;

            if (isValid(nz, nx, ny) && maze[nz][nx][ny] == 1 &&
                dist[nz][nx][ny] == -1)
            {
                dist[nz][nx][ny] = dist[cz][cx][cy] + 1;
                q.emplace(nz, nx, ny);
            }
        }
    }
}

void searchAllMazeCase(int z = 0)
{
    if (z == 5)
    {
        bfs();
        return;
    }

    for (int n = 0; n < 5; n++)
    {
        if (used[n])
            continue;

        used[n] = true;
        for (int r = 0; r < 4; r++)
        {
            for (int i = 0; i < 5; i++)
                for (int j = 0; j < 5; j++)
                    maze[z][i][j] = board[n][r][i][j];

            searchAllMazeCase(z + 1);
        }
        used[n] = false;
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

    /*
        5개의 판 회전 조합 갯수 : 4^5 == 2^10 ~= 1000

        모든 조합에 대해 bfs 로 최단거리 탐색해서 최솟값 구하기

        회전변환행렬
        c -s
        s  c

        반시계 90도 회전변환
        x'.  0 -1 x
        y'   1  0 y

        x' = -y
        y' = x

        x', y' [0, 5) 범위로 되도록 평행이동
        x' = 4 - y
        y' = x
    */

    for (int z = 0; z < 5; z++)
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                cin >> board[z][0][i][j];

    for (int z = 0; z < 5; z++)
    {
        for (int r = 1; r < 4; r++)
        {
            for (int i = 0; i < 5; i++)
                for (int j = 0; j < 5; j++)
                    board[z][r][4 - j][i] = board[z][r - 1][i][j];
        }
    }

    searchAllMazeCase();

    cout << (res == INF ? -1 : res) << '\n';

    // inputFileStream.close();
    return 0;
}

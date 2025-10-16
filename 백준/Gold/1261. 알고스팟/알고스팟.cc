#include <bits/stdc++.h>
using namespace std;

using T = tuple<int, int, int>;
const int INF = 10001;
const int NMX = 100;
int N, M;
int board[NMX + 1][NMX + 1];
int dist[NMX + 1][NMX + 1];

vector<pair<int, int>> moves{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(int x, int y)
{
    return x > 0 && x <= N && y > 0 && y <= M;
}

void initDist()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            dist[i][j] = INF;
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

    // ifstream inputFileStream("input.txt");

    cin >> M >> N;
    for (int i = 1; i <= N; i++)
    {
        string line;
        cin >> line;

        for (int j = 1; j <= M; j++)
        {
            board[i][j] = line[j - 1] - '0';
        }
    }

    initDist();
    priority_queue<T, vector<T>, greater<T>> pq;

    dist[1][1] = 0;
    pq.emplace(0, 1, 1);

    while (!pq.empty())
    {
        auto [d, cx, cy] = pq.top();
        pq.pop();

        if (d > dist[cx][cy])
            continue;

        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;

            if (!isValid(nx, ny))
                continue;

            int isWall = board[nx][ny];
            int nd = d + isWall;

            if (nd < dist[nx][ny])
            {
                dist[nx][ny] = nd;
                pq.emplace(nd, nx, ny);
            }
        }
    }

    cout << dist[N][M];

    // inputFileStream.close();
    return 0;
}
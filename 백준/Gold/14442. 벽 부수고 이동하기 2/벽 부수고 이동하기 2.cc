#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        bfs 최단거리
        dist에 상태추가
    */

    using P = pair<int, int>;
    using T = tuple<int, int, int>;
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> board(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;

        for (int j = 0; j < M; j++)
        {
            board[i][j] = line[j] - '0';
        }
    }

    auto isValid = [&](int x, int y)
    {
        return x >= 0 && x < N && y >= 0 && y < M;
    };

    vector<P> moves{
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}};

    // dp[i][j][k] : {i, j} 까지 벽을 k번 부수고 간 최단거리
    vector<vector<vector<int>>> dist(N, vector<vector<int>>(M, vector<int>(K + 1, -1)));

    // x, y, k(벽부순 횟수)
    queue<T> q;
    q.emplace(0, 0, 0);
    dist[0][0][0] = 1;

    int res = -1;
    while (!q.empty())
    {
        auto [cx, cy, ck] = q.front();
        q.pop();

        if (cx == N - 1 && cy == M - 1)
        {
            res = dist[cx][cy][ck];
            break;
        }

        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;

            if (!isValid(nx, ny))
                continue;

            if (board[nx][ny] == 1 && ck < K && dist[nx][ny][ck + 1] == -1)
            {
                dist[nx][ny][ck + 1] = dist[cx][cy][ck] + 1;
                q.emplace(nx, ny, ck + 1);
            }

            if (board[nx][ny] == 0 && dist[nx][ny][ck] == -1)
            {
                dist[nx][ny][ck] = dist[cx][cy][ck] + 1;
                q.emplace(nx, ny, ck);
            }
        }
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}

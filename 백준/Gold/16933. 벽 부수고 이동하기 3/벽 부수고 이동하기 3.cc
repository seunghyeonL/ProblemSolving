#include <bits/stdc++.h>
using namespace std;

int dist[1002][1002][12][2]{};

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    using P = pair<int, int>;
    using T = tuple<int, int, int, int>;
    int N, M, K;
    cin >> N >> M >> K;

    int INF = 1e9;

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

    // x, y, 벽부순횟수, 낮인지여부
    // vector<vector<vector<vector<int>>>> dist(N, vector<vector<vector<int>>>(M, vector<vector<int>>(K + 1, vector<int>(2, INF))));

    // x, y, 벽부순횟수, 낮인지여부
    queue<T> q;
    q.emplace(0, 0, 0, 1);
    dist[0][0][0][1] = 1;

    /*
        이동 종류

        - 가만히 있기, 그냥이동, 벽부수고 이동 -> 가중치 1
    */

    int res = -1;
    while (!q.empty())
    {
        auto [cx, cy, ch, isDay] = q.front();
        q.pop();

        // cout << cx << cy << ch << isDay << '\n';

        if (cx == N - 1 && cy == M - 1)
        {
            res = dist[cx][cy][ch][isDay];
            break;
        }

        // 가만히 있기
        if (!dist[cx][cy][ch][!isDay])
        {
            q.emplace(cx, cy, ch, !isDay);
            dist[cx][cy][ch][!isDay] = dist[cx][cy][ch][isDay] + 1;
        }

        // 그냥 이동
        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;

            if (isValid(nx, ny) && board[nx][ny] == 0 && !dist[nx][ny][ch][!isDay])
            {
                q.emplace(nx, ny, ch, !isDay);
                dist[nx][ny][ch][!isDay] = dist[cx][cy][ch][isDay] + 1;
            }
        }

        // 벽 이제 못 부수거나 밤이면 넘어가기
        if (ch == K || !isDay)
            continue;

        // 벽부수고 이동
        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;

            if (isValid(nx, ny) && board[nx][ny] == 1 && !dist[nx][ny][ch + 1][!isDay])
            {
                q.emplace(nx, ny, ch + 1, !isDay);
                dist[nx][ny][ch + 1][!isDay] = dist[cx][cy][ch][isDay] + 1;
            }
        }
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
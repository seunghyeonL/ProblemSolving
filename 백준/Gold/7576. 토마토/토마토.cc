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
        출발점이 여러개니 그냥 다익스트라로
        돌려주면서 dist가 작은걸로 갱신
        최종적으로 dist 초기값이 남아있고 그게 토마토 없는 자리가 아니면 -1
        아니면 dist중 최댓값(토마토 없는자리 빼고)
    */

    using P = pair<int, int>; // x, y
    // using T = tuple<int, int, int>; // dist, x, y

    int M, N;
    cin >> M >> N;

    const int INF = 1e9;

    vector<vector<int>> board(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
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

    vector<vector<int>> dist(N, vector<int>(M, INF));

    queue<P> q;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 1)
            {
                q.emplace(i, j);
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();

        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;

            if (isValid(nx, ny) && board[nx][ny] == 0 && dist[nx][ny] == INF)
            {
                dist[nx][ny] = dist[cx][cy] + 1;
                q.emplace(nx, ny);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (dist[i][j] == INF && board[i][j] != -1)
            {
                cout << -1 << '\n';
                return 0;
            }

            if (dist[i][j] < INF)
            {
                res = max(res, dist[i][j]);
            }
        }
    }

    cout << res << '\n';

    // Printc<vector<vector<int>>, Printc<vector<int>>> printc;
    // printc(dist);

    // inputFileStream.close();
    return 0;
}
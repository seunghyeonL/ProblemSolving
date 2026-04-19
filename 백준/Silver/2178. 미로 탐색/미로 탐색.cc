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
        {0, 0} -> {N-1, M-1} 최소 거리
    */

    using P = pair<int, int>;

    int N, M;
    cin >> N >> M;

    vector<string> board(N);

    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
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

    vector<vector<int>> dist(N, vector<int>(M, -1));

    queue<P> q;
    q.push({0, 0});
    dist[0][0] = 0;

    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();

        if (cx == N - 1 && cy == M - 1)
        {
            break;
        }

        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;

            if (isValid(nx, ny) && dist[nx][ny] == -1 && board[nx][ny] == '1')
            {
                q.push({nx, ny});
                dist[nx][ny] = dist[cx][cy] + 1;
            }
        }
    }

    cout << dist[N - 1][M - 1] + 1 << '\n';

    // inputFileStream.close();
    return 0;
}

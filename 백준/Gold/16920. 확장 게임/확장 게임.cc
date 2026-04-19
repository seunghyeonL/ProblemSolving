#include <bits/stdc++.h>
using namespace std;

char board[1001][1001]{};
int S[10]{};

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    using P = pair<int, int>;
    using T = tuple<int, int, int>;
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= K; i++)
    {
        cin >> S[i];
    }

    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;

        for (int j = 0; j < M; j++)
        {
            board[i][j] = line[j];
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

    vector<int> res(K + 1);
    vector<vector<P>> edgeCastles(K + 1);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == '.' || board[i][j] == '#')
                continue;

            res[board[i][j] - '0']++;
            edgeCastles[board[i][j] - '0'].emplace_back(i, j);
        }
    }

    // x, y, 초기상태로부터 거리
    queue<T> q;

    auto bfs = [&](int p) -> int
    {
        int res = 0;

        for (auto [sx, sy] : edgeCastles[p])
        {
            q.emplace(sx, sy, 0);
        }

        edgeCastles[p].clear();

        while (!q.empty())
        {
            auto [cx, cy, cd] = q.front();
            q.pop();

            // cout << p << ' ' << cx << ' ' << cy << ' ' << cd << '\n';
            for (auto [dx, dy] : moves)
            {
                int nx = cx + dx;
                int ny = cy + dy;

                if (isValid(nx, ny) && board[nx][ny] == '.' && cd < S[p])
                {
                    if (cd + 1 == S[p])
                    {
                        edgeCastles[p].emplace_back(nx, ny);
                    }
                    q.emplace(nx, ny, cd + 1);
                    board[nx][ny] = '0' + p;
                    res++;
                }
            }
        }

        return res;
    };

    while (true)
    {
        bool isEnd = true;
        for (int p = 1; p <= K; p++)
        {
            int cnt = bfs(p);
            res[p] += cnt;

            if (cnt != 0)
                isEnd = false;
        }

        if (isEnd)
            break;
    }

    for (int p = 1; p <= K; p++)
        cout << res[p] << ' ';
    cout << '\n';

    // inputFileStream.close();
    return 0;
}
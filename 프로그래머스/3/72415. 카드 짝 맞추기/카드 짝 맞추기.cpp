#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <functional>

using namespace std;

int solution(vector<vector<int>> board, int r, int c)
{
    using P = pair<int, int>;
    int answer = 0;
    int N = 4;
    /*
    카드 종류, 좌표 매핑해놓기

    다음에 없앨 카드 하나 정하고
    뭐부터 없앨지 순서 하나 정해서
    백트래킹
    */

    // Printc<vector<P>, Printp<P>> printc;

    unordered_map<int, vector<P>> cards;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j])
                cards[board[i][j]].emplace_back(i, j);

    // for (auto [n, v] : cards)
    // {
    //     for (auto [i, j] : v)
    //     {
    //         cout << '(' << n << ": (" << i << ", " << j << "))";
    //     }
    //     cout << "\n";
    // }

    vector<P> moves{
        {1, 0}, {0, 1}, {-1, 0}, {0, -1} // down, right, up, left
    };

    auto isValid = [N](int x, int y)
    { return x >= 0 && x < N && y >= 0 && y < N; };

    auto getNextPoints = [&](int x, int y) -> vector<P>
    {
        vector<P> result;

        for (auto [dx, dy] : moves)
        {
            int nx = x + dx;
            int ny = y + dy;

            if (!isValid(nx, ny))
            {
                continue;
            }

            // 그냥 이동
            result.emplace_back(nx, ny);
            if (board[nx][ny])
                continue;

            // ctrl 이동
            while (isValid(nx + dx, ny + dy))
            {
                nx += dx;
                ny += dy;

                if (board[nx][ny])
                {
                    result.emplace_back(nx, ny);
                    break;
                }

                // 끝점
                if (!isValid(nx + dx, ny + dy))
                {
                    result.emplace_back(nx, ny);
                }
            }
        }

        return result;
    };

    auto bfs = [&](int sx, int sy, int tx, int ty) -> int
    {
        vector<vector<int>> dist(4, vector<int>(4, -1));
        queue<P> q;

        dist[sx][sy] = 0;
        q.push({sx, sy});

        while (!q.empty())
        {
            auto [cx, cy] = q.front();
            q.pop();

            if (cx == tx && cy == ty)
            {
                break;
            }

            for (auto [nx, ny] : getNextPoints(cx, cy))
            {
                if (dist[nx][ny] == -1)
                {
                    dist[nx][ny] = dist[cx][cy] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return dist[tx][ty];
    };

    vector<bool> removed(7);

    function<int(int, int)> solve = [&](int cx, int cy) -> int
    {
        int result = 1e9;

        // cout << "cx: " << cx << "cy: " << cy << '\n';
        for (auto [card, points] : cards)
        {
            if (removed[card])
                continue;

            auto [tx1, ty1] = points[0];
            auto [tx2, ty2] = points[1];

            // 첫번째부터 제거
            int result1 = 0;
            result1 += bfs(cx, cy, tx1, ty1) + 1;
            board[tx1][ty1] = 0;
            result1 += bfs(tx1, ty1, tx2, ty2) + 1;
            board[tx2][ty2] = 0;

            removed[card] = true;
            result1 += solve(tx2, ty2);
            removed[card] = false;

            board[tx1][ty1] = card;
            board[tx2][ty2] = card;

            result = min(result, result1);

            // 두번째부터 제거
            int result2 = 0;
            result2 += bfs(cx, cy, tx2, ty2) + 1;
            board[tx2][ty2] = 0;
            result2 += bfs(tx2, ty2, tx1, ty1) + 1;
            board[tx1][ty1] = 0;

            removed[card] = true;
            result2 += solve(tx1, ty1);
            removed[card] = false;

            board[tx1][ty1] = card;
            board[tx2][ty2] = card;

            result = min(result, result2);
        }

        // cout << cx << ' ' << cy << '\n';
        // cout << (result == 1e9 ? 0 : result) << '\n';

        return result == 1e9 ? 0 : result;
    };

    // cout << bfs(r, c, 0, 0) << '\n';
    // cout << bfs(r, c, 3, 1) << '\n';
    // cout << bfs(r, c, 3, 3) << '\n';

    // cout << '\n';

    // cout << bfs(0, 0, r, c) << '\n';
    // cout << bfs(3, 1, r, c) << '\n';
    // cout << bfs(3, 3, r, c) << '\n';

    // printc(getNextPoints(r, c));

    return solve(r, c);
}

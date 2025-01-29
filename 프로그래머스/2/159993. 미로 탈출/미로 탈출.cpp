#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>

using namespace std;

int solution(vector<string> maps)
{
    using Pos = pair<int, int>;

    int answer = 0;

    int N = maps.size();
    int M = maps[0].size();

    Pos startPoint, leverPoint, endPoint;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (maps[i][j] == 'S')
            {
                startPoint = {i, j};
            }
            else if (maps[i][j] == 'L')
            {
                leverPoint = {i, j};
            }
            else if (maps[i][j] == 'E')
            {
                endPoint = {i, j};
            }
        }
    }

    function<int(Pos, Pos)> bfs = [&](Pos s, Pos e) -> int
    {
        vector<Pos> directions{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        vector<vector<bool>> visited(N, vector<bool>(M, false));

        function<bool(Pos)> isValid = [&](Pos p) -> bool
        {
            auto [x, y] = p;
            return x >= 0 && x < N && y >= 0 && y < M && maps[x][y] != 'X' &&
                   !visited[x][y];
        };

        queue<tuple<int, int, int>> q;
        q.push({s.first, s.second, 0});
        visited[s.first][s.second] = true;

        while (!q.empty())
        {
            auto [curX, curY, dist] = q.front();
            q.pop();

            for (auto [diffX, diffY] : directions)
            {
                int nextX = curX + diffX;
                int nextY = curY + diffY;

                if (nextX == e.first && nextY == e.second)
                {
                    return dist + 1;
                }

                if (!isValid({nextX, nextY}))
                {
                    continue;
                }

                q.push({nextX, nextY, dist + 1});
                visited[nextX][nextY] = true;
            }
        }
        return -1;
    };

    int leverDist = bfs(startPoint, leverPoint);
    if (leverDist == -1)
    {
        return -1;
    }

    answer += leverDist;

    int endDist = bfs(leverPoint, endPoint);
    if (endDist == -1)
    {
        return -1;
    }

    answer += endDist;
    return answer;
}
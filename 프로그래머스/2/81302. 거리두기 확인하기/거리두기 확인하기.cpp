#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    vector<pair<int, int>> directions{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    for (auto place : places)
    {
        // prints(place);
        auto isClose = [&](int x, int y) -> bool
        {
            bool result = false;
            vector<vector<bool>> visited(5, vector<bool>(5, false));

            auto isValid = [&](int x, int y) -> bool
            {
                return x >= 0 && x < 5 && y >= 0 && y < 5 &&
                       place[x][y] != 'X' && !visited[x][y];
            };

            queue<tuple<int, int, int>> q;
            q.push({x, y, 0});
            visited[x][y] = true;

            while (!q.empty())
            {
                auto [curX, curY, dist] = q.front();
                q.pop();

                if (place[curX][curY] == 'P' && (curX != x || curY != y))
                {
                    // cout << "x: " << x << " y: " << y << " curX: " << curX
                    //      << " curY " << curY << '\n';
                    // for (int i = 0; i < 5; i++)
                    // {
                    //     prints(visited[i]);
                    // }

                    result = true;
                    break;
                }

                for (auto [diffX, diffY] : directions)
                {
                    int nextX = curX + diffX;
                    int nextY = curY + diffY;

                    // cout << "nextX: " << nextX << " nextY: " << nextY <<
                    // '\n';

                    if (!isValid(nextX, nextY) || dist == 2)
                    {
                        continue;
                    }
                    // cout << "re nextX: " << nextX << " nextY: " << nextY
                    //      << '\n';
                    q.push({nextX, nextY, dist + 1});
                    visited[nextX][nextY] = true;
                }
            }
            return result;
        };

        int result = 1;
        for (int i = 0; i < 5; i++)
        {
            bool closeFlag = false;
            for (int j = 0; j < 5; j++)
            {
                if (place[i][j] == 'P' && isClose(i, j))
                {
                    result = 0;
                    closeFlag = true;
                    break;
                }
            }
            if (closeFlag)
                break;
        }
        answer.push_back(result);
    }

    return answer;
}

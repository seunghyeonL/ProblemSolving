#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <functional>

using namespace std;

int solution(vector<string> board)
{
    int answer = -1;
    int N = board.size();
    int M = board[0].size();

    vector<vector<bool>> isVisited(N, vector<bool>(M, false));

    auto isValid = [&](int x, int y) -> bool
    { return x >= 0 && x < N && y >= 0 && y < M && board[x][y] != 'D'; };

    vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    pair<int, int> startPoint;
    for (int i = 0; i < N; ++i)
    {
        bool findFlag = false;
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] == 'R')
            {
                startPoint = {i, j};
                findFlag = true;
                break;
            }
        }
        if (findFlag)
            break;
    }

    queue<tuple<int, int, int>> q; // {x, y, cnt}
    q.push({startPoint.first, startPoint.second, 0});
    isVisited[startPoint.first][startPoint.second] = true;

    while (!q.empty())
    {
        auto [curX, curY, curCnt] = q.front();
        q.pop();
        
        bool findFlag = false;
        for (auto direction : directions)
        {
            auto [diffX, diffY] = direction;
            int nextX = curX;
            int nextY = curY;

            // vaild한 곳 끝까지 이동
            while (isValid(nextX + diffX, nextY + diffY))
            {
                nextX += diffX;
                nextY += diffY;
            }

            // 도착지가 방문한곳이면 제자리로
            if (isVisited[nextX][nextY])
            {
                continue;
            }

            if (board[nextX][nextY] == 'G')
            {
                answer = curCnt + 1;
                findFlag = true;
                break;
            }

            q.push({nextX, nextY, curCnt + 1});
            isVisited[nextX][nextY] = true;
        }
        if(findFlag)
            break;
    }

    return answer;
}
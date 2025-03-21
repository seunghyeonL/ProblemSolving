#include <string>
#include <vector>
#include <functional>

using namespace std;

vector<int> solution(vector<string> grid)
{
    vector<int> answer;
    int N = grid.size();
    int M = grid[0].size();

    enum Direction
    {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };
    vector<pair<int, int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    // 각 셀에서 (1, 0), (0, -1), (-1, 0), (0, 1) 방향으로 움직였는지 여부
    vector<vector<vector<bool>>> possibleDirections(
        N, vector<vector<bool>>(M, {true, true, true, true}));

    // 빛이 curDir방향 으로 c 문자에 들어갈 때 바뀌는 방향
    auto getNextDirection = [&](char c, Direction curDir) -> Direction
    {
        Direction result;
        switch (c)
        {
        case 'S':
            result = curDir;
            break;
        case 'L':
            // result = curDir == UP ? LEFT : Direction(curDir - 1);
            result = Direction((curDir + 3) % 4);
            break;
        case 'R':
            // result = curDir == LEFT ? UP : Direction(curDir + 1);
            result = Direction((curDir + 1) % 4);
            break;
        }
        return result;
    };

    // x, y 점에서 dir 방향으로 갈때 도착점
    auto getNextPos = [&](int x, int y, Direction dir) -> pair<int, int>
    {
        auto [diffX, diffY] = directions[dir];
        int nextX = (x + diffX + N) % N;
        int nextY = (y + diffY + M) % M;

        return {nextX, nextY};
    };

    // 순회? 함수
    auto traverse = [&](pair<int, int> startPos, Direction startDir) -> int
    {
        auto [cx, cy] = startPos;
        Direction curDir = startDir;
        int cnt = 0;

        while (possibleDirections[cx][cy][curDir])
        {
            auto [nx, ny] = getNextPos(cx, cy, curDir);
            auto nextDir = getNextDirection(grid[nx][ny], curDir);

            // 한번 간 경로는 다시 못가도록 체크
            possibleDirections[cx][cy][curDir] = false;
            cx = nx;
            cy = ny;
            curDir = nextDir;

            cnt++;
        }

        return cnt;
    };

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int dIdx = 0; dIdx < 4; dIdx++)
            {
                Direction dir = Direction(dIdx);
                // 가능 경로일때만 실행
                if (possibleDirections[i][j][dir])
                {
                    answer.push_back(traverse({i, j}, dir));
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}
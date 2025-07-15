#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");
    using P = pair<int, int>;
    using T = tuple<int, int, int>;

    int K;
    cin >> K;

    int W, H;
    cin >> W >> H;

    vector<vector<int>> board(H, vector<int>(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> board[i][j];
        }
    }

    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(K + 1, 0))); // 세로, 가로, 말이동횟수 ; 거리
    queue<T> q;                                                                         // 세로, 가로, 말이동횟수
    q.push({0, 0, 0});
    board[0][0] = 1;

    vector<P> moveDirection{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // R, D, L, U
    vector<P> horseMoveDirection{{{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}}};

    auto isValidPoint = [&](P point)
    {
        auto [x, y] = point;
        return x >= 0 && x < H && y >= 0 && y < W && !board[x][y];
    };

    auto getNormalNextPoints = [&](T prevPoint) -> vector<T>
    {
        vector<T> nextPoints;
        auto [prevX, prevY, prevHorseCnt] = prevPoint;

        for (auto [diffX, diffY] : moveDirection)
        {
            int nextX = prevX + diffX;
            int nextY = prevY + diffY;

            if (isValidPoint({nextX, nextY}))
            {
                nextPoints.push_back({nextX, nextY, prevHorseCnt});
            }
        }

        return nextPoints;
    };

    auto getHorseNextPoints = [&](T prevPoint) -> vector<T>
    {
        vector<T> nextPoints;
        auto [prevX, prevY, prevHorseCnt] = prevPoint;
        if (prevHorseCnt == K)
        {
            return nextPoints;
        }

        for (auto [diffX, diffY] : horseMoveDirection)
        {
            int nextX = prevX + diffX;
            int nextY = prevY + diffY;

            if (isValidPoint({nextX, nextY}))
            {
                nextPoints.push_back({nextX, nextY, prevHorseCnt + 1});
            }
        }

        return nextPoints;
    };

    int answer = -1;

    while (!q.empty())
    {
        auto [curX, curY, curHorseCnt] = q.front();
        q.pop();

        if (curX == H - 1 && curY == W - 1)
        {
            answer = dist[curX][curY][curHorseCnt];
            break;
        }

        for (auto [nextX, nextY, nextHorseCnt] : getNormalNextPoints({curX, curY, curHorseCnt}))
        {
            if (dist[nextX][nextY][nextHorseCnt] == 0)
            {
                dist[nextX][nextY][nextHorseCnt] = dist[curX][curY][curHorseCnt] + 1;
                q.push({nextX, nextY, nextHorseCnt});
            }
        }

        for (auto [nextX, nextY, nextHorseCnt] : getHorseNextPoints({curX, curY, curHorseCnt}))
        {
            if (dist[nextX][nextY][nextHorseCnt] == 0)
            {
                dist[nextX][nextY][nextHorseCnt] = dist[curX][curY][curHorseCnt] + 1;
                q.push({nextX, nextY, nextHorseCnt});
            }
        }
    }

    cout << answer;
    // inputFileStream.close();
    return 0;
}

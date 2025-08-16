#include <string>
#include <vector>
#include <tuple>

using namespace std;

int solution(string numbers)
{
    using T = tuple<int, int, int>; // cost, u, v
    const int INF = 1e8;
    int answer = INF;

    vector<vector<int>> keypad(3, vector<int>(3));

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            keypad[i][j] = 1 + i + 3 * j;

    auto isValid = [](int x, int y)
    {
        return x >= 0 && x < 3 && y >= 0 && y < 3;
    };

    // 누를때 1을 추가하는 방식으로
    vector<T> moves{
        {2, 1, 0},
        {2, -1, 0},
        {2, 0, 1},
        {2, 0, -1},
        {3, 1, 1},
        {3, -1, 1},
        {3, -1, -1},
        {3, 1, -1}};

    vector<vector<int>> dist(10, vector<int>(10, INF));
    for (int i = 0; i < 10; i++)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (auto [w, dx, dy] : moves)
            {
                int nx = i + dx;
                int ny = j + dy;

                if (isValid(nx, ny))
                {
                    int u = keypad[i][j];
                    int v = keypad[nx][ny];
                    dist[u][v] = w;
                    dist[v][u] = w;
                }
            }
        }
    }

    dist[7][0] = 3;
    dist[0][7] = 3;
    dist[9][0] = 3;
    dist[0][9] = 3;
    dist[8][0] = 2;
    dist[0][8] = 2;

    for (int k = 0; k < 10; k++)
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 0; i < 10; i++)
    {
        dist[i][i] = 1;
    }

    // Printc<vector<vector<int>>, Printc<vector<int>>> printc;
    // printc(dist);

    int size = numbers.size();
    vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(10, vector<int>(10, INF))); // dp[n][l][k] : n번째 숫자에 l, k위치에 손가락 둘때의 최소 누적값
    dp[0][4][6] = 0;

    for (int i = 1; i <= size; i++)
    {
        int c = numbers[i - 1];
        int n = c - '0';

        for (int x = 0; x < 10; x++)
        {
            for (int y = 0; y < 10; y++)
            {
                if (dp[i - 1][x][y] < INF)
                {
                    if (y != n)
                        dp[i][n][y] = min(dp[i][n][y], dp[i - 1][x][y] + dist[x][n]);

                    if (x != n)
                        dp[i][x][n] = min(dp[i][x][n], dp[i - 1][x][y] + dist[y][n]);
                }
            }
        }
    }

    int last = numbers.back() - '0';
    for (int i = 0; i < 10; i++)
    {
        answer = min(answer, dp[size][last][i]);
        answer = min(answer, dp[size][i][last]);
    }

    return answer;
}

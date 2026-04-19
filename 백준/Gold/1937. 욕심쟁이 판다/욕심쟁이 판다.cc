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
        방향그래프
        memoization
    */

    int n;
    cin >> n;

    using P = pair<int, int>;
    vector<vector<int>> board(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    auto isValid = [&](int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < n;
    };

    vector<P> moves{
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}};

    vector<vector<vector<P>>> adj(n, vector<vector<P>>(n));
    vector<vector<int>> indegrees(n, vector<int>(n));

    for (int cx = 0; cx < n; cx++)
    {
        for (int cy = 0; cy < n; cy++)
        {
            for (auto [dx, dy] : moves)
            {
                int nx = cx + dx;
                int ny = cy + dy;

                if (isValid(nx, ny) && board[cx][cy] < board[nx][ny])
                {
                    adj[cx][cy].push_back({nx, ny});
                    indegrees[nx][ny]++;
                }
            }
        }
    }

    // memo[i][j] : i, j 점에서 출발할때 최대 칸수
    vector<vector<int>> memo(n, vector<int>(n, 0));

    function<void(int, int)> dfs = [&](int cx, int cy)
    {
        if (memo[cx][cy] > 0)
            return;

        int res = 1;
        for (auto [nx, ny] : adj[cx][cy])
        {
            dfs(nx, ny);
            res = max(res, memo[nx][ny] + 1);
        }

        memo[cx][cy] = res;
    };

    int res = 0;
    for (int cx = 0; cx < n; cx++)
    {
        for (int cy = 0; cy < n; cy++)
        {
            // dfs로 최대 길이 찾기
            if (indegrees[cx][cy] == 0)
            {
                dfs(cx, cy);
                res = max(res, memo[cx][cy]);
            }
        }
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}

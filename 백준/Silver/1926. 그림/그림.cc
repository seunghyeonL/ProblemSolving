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
        클러스터 크기 최댓값 찾기
    */

    using P = pair<int, int>;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    auto isValid = [&](int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    vector<P> moves{
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}};

    vector<vector<bool>> visited(n, vector<bool>(m));

    function<int(int, int)> getClusterSize = [&](int cx, int cy) -> int
    {
        visited[cx][cy] = true;
        int res = 1;
        for (auto [dx, dy] : moves)
        {
            int nx = cx + dx;
            int ny = cy + dy;

            if (!isValid(nx, ny) || visited[nx][ny] || board[nx][ny] == 0)
                continue;

            res += getClusterSize(nx, ny);
        }

        return res;
    };

    int cnt = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && board[i][j] == 1)
            {
                mx = max(mx, getClusterSize(i, j));
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
    cout << mx << '\n';

    // inputFileStream.close();
    return 0;
}

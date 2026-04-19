#include <bits/stdc++.h>
using namespace std;

const int NMX = 500;
int N, M; // 세로, 가로
int arr[NMX][NMX];
int dp[NMX][NMX]; // {0, 0} -> {i, j} 경로 수

vector<pair<int, int>> moves{
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}};

bool isValid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

void init_dp()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            dp[i][j] = -1;
}

int solve(int cx, int cy)
{
    if (dp[cx][cy] >= 0)
        return dp[cx][cy];

    int res = 0;
    for (auto [dx, dy] : moves)
    {
        int nx = cx + dx;
        int ny = cy + dy;

        if (isValid(nx, ny) && arr[nx][ny] > arr[cx][cy])
        {
            res += solve(nx, ny);
        }
    }

    return dp[cx][cy] = res;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
     */

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

    init_dp();
    dp[0][0] = 1;
    cout << solve(N - 1, M - 1);

    // inputFileStream.close();
    return 0;
}
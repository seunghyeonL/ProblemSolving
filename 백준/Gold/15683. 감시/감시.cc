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
        6 : 벽
        1 ~ 5 : CCTV
        CCTV는 벽에는 막히고 CCTV는 뚫고 감시 가능
        CCTV는 최대 8개 -> 각각 회전 4번; 4^8 == 2 ^ 16 ~= 1000 ^ 64 -> 완전탐색으로 충분
        CCTV를 회전시켜갈때 사각지대의 최소 크기 찾기

        1, 2, 3, 4, 5 각각 감시방향 경우의 수들 미리 만들어놓기
        백트래킹을 위해 각 CCTV로 감시하는 위치 #로 채울때 이미 #이던 부분 기록해놓고 복원할때 유지하기
    */

    using P = pair<int, int>;       // x, y
    using T = tuple<int, int, int>; // cctv종류, x, y
    int N, M;
    cin >> N >> M;

    vector<T> cctvs;
    vector<vector<char>> board(N, vector<char>(M));

    auto isCCTV = [&](int x, int y)
    {
        return board[x][y] >= '1' && board[x][y] <= '5';
    };

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (isCCTV(i, j))
            {
                cctvs.push_back({board[i][j] - '0', i, j});
            }
        }
    }

    auto isValid = [&](int x, int y)
    {
        return x >= 0 && x < N && y >= 0 && y < M;
    };

    vector<vector<vector<P>>> monitorInfo(6);
    vector<vector<P>> monitor1(4);
    monitor1[0] = {{1, 0}};
    monitor1[1] = {{0, 1}};
    monitor1[2] = {{-1, 0}};
    monitor1[3] = {{0, -1}};

    vector<vector<P>> monitor2(2);
    monitor2[0] = {{1, 0}, {-1, 0}};
    monitor2[1] = {{0, 1}, {0, -1}};

    vector<vector<P>> monitor3(4);
    monitor3[0] = {{1, 0}, {0, -1}};
    monitor3[1] = {{0, -1}, {-1, 0}};
    monitor3[2] = {{-1, 0}, {0, 1}};
    monitor3[3] = {{0, 1}, {1, 0}};

    vector<vector<P>> monitor4(4);
    monitor4[0] = {{-1, 0}, {0, 1}, {0, -1}};
    monitor4[1] = {{1, 0}, {0, 1}, {0, -1}};
    monitor4[2] = {{1, 0}, {-1, 0}, {0, -1}};
    monitor4[3] = {{1, 0}, {-1, 0}, {0, 1}};

    vector<vector<P>> monitor5(1);
    monitor5[0] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    monitorInfo[1] = monitor1;
    monitorInfo[2] = monitor2;
    monitorInfo[3] = monitor3;
    monitorInfo[4] = monitor4;
    monitorInfo[5] = monitor5;

    auto updateDetectingArea = [&](int cx, int cy, const vector<P> &directions)
    {
        for (auto [dx, dy] : directions)
        {
            int nx = cx + dx;
            int ny = cy + dy;
            while (isValid(nx, ny) && board[nx][ny] != '6')
            {
                if (!isCCTV(nx, ny))
                {
                     board[nx][ny] = '#';
                }

                nx += dx;
                ny += dy;
            }
        }
    };

    int res = 1e9;

    // for (auto [ctype, cx, cy] : cctvs)
    // {
    //     cout << ctype << ' ' << cx << ' ' << cy << '\n';
    // }
    // cout << '\n';

    function<void(int)> solveRec = [&](int idx)
    {
        if (idx == cctvs.size())
        {
            int cdd = 0;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    // cout << board[i][j] << ' ';
                    if (board[i][j] == '0')
                        cdd++;
                }
                // cout << '\n';
            }
            // cout << '\n';

            res = min(res, cdd);

            return;
        }

        auto [ctype, cx, cy] = cctvs[idx];

        for (const vector<P> &directions : monitorInfo[ctype])
        {
            vector<vector<char>> preBoard = board;
            // 전 방향에 대해서 처리하고 이후 재귀 들어가고 이후 전 방향에 대해 복원해야함
            updateDetectingArea(cx, cy, directions);
            solveRec(idx + 1);
            board = preBoard;
        }
    };

    solveRec(0);

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}

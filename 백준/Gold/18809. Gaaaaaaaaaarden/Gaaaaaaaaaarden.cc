#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
int board[51][51];
P visited[51][51]; // 배양액종류(R: 1, G: 2, 꽃: 3, 없음: 0), 번진 시간
int N, M, G, R;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        가능한 빨간 배양액, 초록 배양액 위치를 모두 고르고
        bfs로 퍼뜨리며 꽃 개수 확인
    */

    cin >> N >> M >> G >> R;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    vector<P> tpoints;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (board[i][j] == 2)
                tpoints.emplace_back(i, j);

    int tsize = tpoints.size();

    // 초록 : 2, 빨강 : 1, 안쓰기 : 0
    vector<int> mask(tsize);
    fill(mask.begin(), mask.begin() + G, 2);
    fill(mask.begin() + G, mask.begin() + G + R, 1);

    auto isValid = [&](int x, int y)
    {
        return x >= 0 && x < N && y >= 0 && y < M;
    };

    vector<P> moves{
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}};

    auto resetVisited = [&]()
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                visited[i][j] = {0, 0};
    };

    // x, y
    queue<P> q;

    int res = 0;

    do
    {
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < M; j++)
        //         cout << visited[i][j].first << ' ';

        //     cout << '\n';
        // }
        // cout << '\n';

        resetVisited();

        for (int i = 0; i < tsize; i++)
        {
            if (mask[i] == 1)
            {
                auto [x, y] = tpoints[i];
                visited[x][y] = {1, 0};
                q.emplace(x, y);
            }
            else if (mask[i] == 2)
            {
                auto [x, y] = tpoints[i];
                visited[x][y] = {2, 0};
                q.emplace(x, y);
            }
        }

        int fcnt = 0;

        while (!q.empty())
        {
            auto [cx, cy] = q.front();
            q.pop();

            auto [cc, ct] = visited[cx][cy];

            if (cc == 3)
                continue;

            for (auto [dx, dy] : moves)
            {
                int nx = cx + dx;
                int ny = cy + dy;
                int nc = cc;
                int nt = ct + 1;

                if (!isValid(nx, ny) || board[nx][ny] == 0)
                    continue;

                auto [vc, vt] = visited[nx][ny];

                if (vc == 0)
                {
                    visited[nx][ny] = {nc, nt};
                    q.emplace(nx, ny);
                    continue;
                }

                if (vc != 3 && vc != nc && vt == nt)
                {
                    // cout << nx << ' ' << ny << '\n';
                    visited[nx][ny] = {3, nt};
                    fcnt++;
                }
            }
        }

        res = max(res, fcnt);

    } while (prev_permutation(mask.begin(), mask.end()));

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}

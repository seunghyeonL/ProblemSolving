#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

// i : 흑 백 여부 ( (x + y) % 2 )
// j : 그 색깔인 오른쪽 아래 대각선 ( x + y )
// board[i][j] : 해당 i,  j 대각선에 포함된 점들
vector<P> board[2][20];
int N;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        한 대각선에 하나만 배치하는 식으로 넘어가면서
        다른 대각선은 사용 여부 체크
    */

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            int el;
            cin >> el;

            if (el == 1)
            {
                board[(i + j) % 2][i + j].emplace_back(i, j);
            }
        }

    auto isValid = [&](int x, int y)
    {
        return x >= 0 && x < N && y >= 0 && y < N;
    };

    // 오른쪽 위방향 대각선
    // y = x + c => c = x - y + N - 1 [0, 2 * (N - 1)]
    vector<bool> visited(2 * N);

    vector<int> res(2);
    function<void(int, int, int)> rec = [&](int idx, int cnt, int color)
    {
        if (idx == 2 * N)
        {
            res[color] = max(res[color], cnt);
            return;
        }

        // 가능한거 하나 비숍 설치
        for (auto [x, y] : board[color][idx])
        {
            if (!visited[x - y + N - 1])
            {
                visited[x - y + N - 1] = true;
                rec(idx + 1, cnt + 1, color);
                visited[x - y + N - 1] = false;
            }
        }

        // 그냥 넘어가기
        rec(idx + 1, cnt, color);
    };

    rec(0, 0, 0);
    rec(0, 0, 1);

    cout << res[0] + res[1] << '\n';

    // inputFileStream.close();
    return 0;
}


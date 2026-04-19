#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
int N;

int board[101][101];

vector<P> dir{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
vector<int> d_curve[4][11]; // d_curve[i][j] : i방향으로 시작하는 j세대
                            // 드래곤 커브 방향 배열

void draw_curve(int sx, int sy, int d, int g)
{
    board[sx][sy] = 1;
    int cx = sx;
    int cy = sy;

    for (int el : d_curve[d][g])
    {
        auto [dx, dy] = dir[el];

        cx += dx;
        cy += dy;

        board[cx][cy] = 1;
    }
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     */

    // ifstream inputFileStream("input.txt");

    cin >> N;

    for (int d = 0; d <= 3; d++)
    {
        d_curve[d][0].push_back(d);
    }

    for (int g = 1; g <= 10; g++)
    {
        for (int d = 0; d <= 3; d++)
        {
            vector<int> pc = d_curve[d][g - 1];
            d_curve[d][g] = pc;
            int len = pc.size();

            for (int i = len - 1; i >= 0; i--)
            {
                int nd = (pc[i] + 1) % 4;
                d_curve[d][g].push_back(nd);
            }
        }
    }

    // for (int d = 0; d <= 3; d++)
    // {
    //     for (int el : d_curve[d][1])
    //     {
    //         cout << el << ' ';
    //     }
    //     cout << '\n';
    // }

    for (int i = 0; i < N; i++)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        // 문제는 가로가 x, 세로가 y인데
        // 난 세로 y 가로 x로 짰으니 반대로 넣기
        draw_curve(y, x, d, g);
    }

    int ans = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (board[i][j] && board[i][j + 1] && board[i + 1][j] &&
                board[i + 1][j + 1])
                ans++;
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
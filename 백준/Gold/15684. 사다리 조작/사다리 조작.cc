#include <bits/stdc++.h>
using namespace std;

const int NMX = 10;
const int HMX = 30;
int N, M, H;

bool used[HMX + 1][NMX + 1];
vector<pair<int, int>> row_pos;

bool is_correct()
{
    for (int j = 1; j < N; j++)
    {
        int cur = j;
        for (int i = 1; i <= H; i++)
        {
            if (used[i][cur])
                cur++;
            else if (used[i][cur - 1])
                cur--;
        }
        if (cur != j)
            return false;
    }

    return true;
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

    cin >> N >> M >> H;

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;

        used[x][y] = true;
    }

    if (is_correct())
    {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (!used[i][j - 1] && !used[i][j] && !used[i][j + 1])
                row_pos.emplace_back(i, j);
        }
    }

    int size = row_pos.size();
    int ans = 4;

    for (int i = 0; i < size && ans > 1; i++)
    {
        auto [ix, iy] = row_pos[i];
        used[ix][iy] = true;
        if (is_correct())
            ans = min(ans, 1);

        for (int j = i + 1; j < size && ans > 2; j++)
        {
            auto [jx, jy] = row_pos[j];
            if (used[jx][jy - 1] || used[jx][jy] || used[jx][jy + 1])
                continue;

            used[jx][jy] = true;
            if (is_correct())
                ans = min(ans, 2);

            for (int k = j + 1; k < size && ans > 3; k++)
            {
                auto [kx, ky] = row_pos[k];
                if (used[kx][ky - 1] || used[kx][ky] || used[kx][ky + 1])
                    continue;

                used[kx][ky] = true;
                if (is_correct())
                    ans = min(ans, 3);
                used[kx][ky] = false;
            }
            used[jx][jy] = false;
        }
        used[ix][iy] = false;
    }

    cout << (ans == 4 ? -1 : ans);

    // inputFileStream.close();
    return 0;
}
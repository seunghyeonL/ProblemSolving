#include <bits/stdc++.h>
using namespace std;

const int NMX = 3000;
int N;
// 좌표압축된 board
// 각 좌표값은 그 cell이 채워졌는지 아닌지 여부
short board[2 * NMX][2 * NMX];

tuple<int, int, int, int> pos[NMX]; // 직사각형 모서리 두개

vector<int> comp_x;
vector<int> comp_y;

unordered_map<int, int> idx_x;
unordered_map<int, int> idx_y;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        pos[i] = {x1, y1, x2, y2};

        comp_x.push_back(x1);
        comp_x.push_back(x2);
        comp_y.push_back(y1);
        comp_y.push_back(y2);
    }

    sort(comp_x.begin(), comp_x.end());
    sort(comp_y.begin(), comp_y.end());

    comp_x.erase(unique(comp_x.begin(), comp_x.end()), comp_x.end());
    comp_y.erase(unique(comp_y.begin(), comp_y.end()), comp_y.end());

    int sz_x = comp_x.size();
    int sz_y = comp_y.size();

    for (int i = 0; i < sz_x; i++)
    {
        int x = comp_x[i];
        idx_x[x] = i;
    }

    for (int i = 0; i < sz_y; i++)
    {
        int y = comp_y[i];
        idx_y[y] = i;
    }

    for (int i = 0; i < N; i++)
    {
        auto [x1, y1, x2, y2] = pos[i];

        int ix1 = idx_x[x1];
        int ix2 = idx_x[x2];
        int iy1 = idx_y[y1];
        int iy2 = idx_y[y2];

        board[ix1][iy1] += 1;
        board[ix1][iy2] -= 1;
        board[ix2][iy1] -= 1;
        board[ix2][iy2] += 1;
    }

    for (int i = 0; i < sz_x; i++)
    {
        inclusive_scan(board[i], board[i] + sz_y, board[i]);
    }

    for (int j = 0; j < sz_y; j++)
    {
        for (int i = 1; i < sz_x; i++)
        {
            board[i][j] += board[i - 1][j];
        }
    }

    // for (int i = 0; i < sz_x; i++)
    // {
    //     for (int j = 0; j < sz_y; j++)
    //     {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    long long ans = 0;
    for (int xi = 0; xi < sz_x; xi++)
    {
        for (int yi = 0; yi < sz_y; yi++)
        {
            if (board[xi][yi])
            {
                int diff_x = comp_x[xi + 1] - comp_x[xi];
                int diff_y = comp_y[yi + 1] - comp_y[yi];

                ans += (long long)diff_x * diff_y;
            }
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}

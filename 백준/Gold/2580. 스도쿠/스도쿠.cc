#include <bits/stdc++.h>
using namespace std;

int board[9][9];
vector<pair<int, int>> blanks;
int sz;

bool used_row[9][10];
bool used_col[9][10];
bool used_box[9][10];

int get_box_idx(int x, int y)
{
    return (x / 3) * 3 + y / 3;
}

void rec(int idx_blank, bool &found)
{
    if (idx_blank == sz)
    {
        found = true;
        return;
    }

    auto [cx, cy] = blanks[idx_blank];

    for (int i = 1; i <= 9; i++)
    {
        if (used_row[cx][i] || used_col[cy][i] ||
            used_box[get_box_idx(cx, cy)][i])
            continue;

        board[cx][cy] = i;
        used_row[cx][i] = true;
        used_col[cy][i] = true;
        used_box[get_box_idx(cx, cy)][i] = true;

        rec(idx_blank + 1, found);
        if (found)
            break;

        board[cx][cy] = 0;
        used_row[cx][i] = false;
        used_col[cy][i] = false;
        used_box[get_box_idx(cx, cy)][i] = false;
    }
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            int n;
            cin >> n;
            board[i][j] = n;

            if (n == 0)
            {
                blanks.emplace_back(i, j);
                continue;
            }

            used_row[i][n] = true;
            used_col[j][n] = true;
            used_box[get_box_idx(i, j)][n] = true;
        }

    sz = blanks.size();

    bool found = false;
    rec(0, found);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    // inputFileStream.close();
    return 0;
}
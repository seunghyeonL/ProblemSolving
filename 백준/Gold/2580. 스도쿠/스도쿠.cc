#include <bits/stdc++.h>
using namespace std;

int board[9][9];
vector<pair<int, int>> blanks;
int sz;

set<int> unused_row[9];
set<int> unused_col[9];
set<int> unused_box[9];

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
        if (!unused_row[cx].count(i) || !unused_col[cy].count(i) ||
            !unused_box[get_box_idx(cx, cy)].count(i))
            continue;

        board[cx][cy] = i;
        unused_row[cx].erase(i);
        unused_col[cy].erase(i);
        unused_box[get_box_idx(cx, cy)].erase(i);

        rec(idx_blank + 1, found);
        if (found)
            break;

        board[cx][cy] = 0;
        unused_row[cx].insert(i);
        unused_col[cy].insert(i);
        unused_box[get_box_idx(cx, cy)].insert(i);
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
    {
        unused_row[i].insert({1, 2, 3, 4, 5, 6, 7, 8, 9});
        unused_col[i].insert({1, 2, 3, 4, 5, 6, 7, 8, 9});
        unused_box[i].insert({1, 2, 3, 4, 5, 6, 7, 8, 9});
    }

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

            unused_row[i].erase(n);
            unused_col[j].erase(n);
            unused_box[get_box_idx(i, j)].erase(n);
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
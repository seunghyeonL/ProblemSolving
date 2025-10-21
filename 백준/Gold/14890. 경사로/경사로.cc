#include <bits/stdc++.h>
using namespace std;

const int NMX = 100;
int N, L;

int board[NMX][NMX];

bool check_line(const vector<int> &line, bool debug)
{
    bool prev_up = true;
    bool ret = true;

    int cnt = 1;
    for (int i = 1, p = line[0]; i < N; i++)
    {
        // if (debug)
        //     cout << i << '\n';
        int c = line[i];

        if (prev_up)
        {
            if (p < c)
            {
                if (c - p > 1 || cnt < L)
                {
                    ret = false;
                    break;
                }

                cnt = 1;
            }
            else if (p > c)
            {
                if (p - c > 1)
                {
                    ret = false;
                    break;
                }

                prev_up = false;
                cnt = 1;
            }
            else
            {
                cnt++;
            }
            p = c;
        }
        else
        {
            if (p < c)
            {
                if (c - p > 1 || cnt < 2 * L)
                {
                    ret = false;
                    break;
                }

                prev_up = true;
                cnt = 1;
            }
            else if (p > c)
            {
                if (p - c > 1 || cnt < L)
                {
                    ret = false;
                    break;
                }

                cnt = 1;
            }
            else
            {
                cnt++;
            }
            p = c;
        }
    }

    if (ret && !prev_up && cnt < L)
    {
        ret = false;
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        N^2 == 10^4

     */

    // ifstream inputFileStream("input.txt");

    cin >> N >> L;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        vector<int> row, col;

        for (int j = 0; j < N; j++)
        {
            row.push_back(board[i][j]);
            col.push_back(board[j][i]);
        }

        if (check_line(row, false))
        {
            // cout << "r " << i << '\n';
            ans++;
        }
        if (check_line(col, false))
        {
            // cout << "c " << i << '\n';
            ans++;
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
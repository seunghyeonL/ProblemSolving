#include <bits/stdc++.h>
using namespace std;

vector<string> solveRec(int N)
{
    vector<string> res(N, string(2 * N - 1, ' '));

    if (N == 3)
    {
        res[0][2] = '*';
        res[1][1] = '*';
        res[1][3] = '*';

        fill(res[2].begin(), res[2].end(), '*');
        return res;
    }

    vector<string> part = solveRec(N / 2);

    for (int i = 0; i < N / 2; i++)
    {
        // res의 가로줄 중간 idx는 N - 1
        // part의 가로줄 중간 idx는 N / 2 - 1;
        int m = N / 2;

        res[i][2 * m - 1] = part[i][m - 1];
        res[i + m][m - 1] = part[i][m - 1];
        res[i + m][3 * m - 1] = part[i][m - 1];

        for (int d = 1; d < m; d++)
        {
            // 위쪽 부분 삼각형
            res[i][2 * m - 1 + d] = part[i][m - 1 + d];
            res[i][2 * m - 1 - d] = part[i][m - 1 - d];

            // 왼쪽 아래 부분 삼각형
            res[i + m][m - 1 + d] = part[i][m - 1 + d];
            res[i + m][m - 1 - d] = part[i][m - 1 - d];

            // 오른쪽 아래 부분 삼각형
            res[i + m][3 * m - 1 + d] = part[i][m - 1 + d];
            res[i + m][3 * m - 1 - d] = part[i][m - 1 - d];
        }
    }

    return res;
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

    int N;
    cin >> N;

    vector<string> res = solveRec(N);

    for (string line : res)
    {
        cout << line << '\n';
    }

    // inputFileStream.close();
    return 0;
}

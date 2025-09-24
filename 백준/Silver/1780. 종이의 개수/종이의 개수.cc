#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> v(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
            v[i][j]++;
        }
    }

    // res[0] : 0개수, res[1] : 1개수, res[2] : 2개수
    vector<int> res(3);

    // 0 : 다 0
    // 1 : 다 1
    // 2 : 다 2
    // 3 : mix
    function<int(int, int, int, int)> DnC = [&](int x1, int y1, int x2,
                                                int y2) -> int
    {
        if (x1 == x2 && y1 == y2)
        {
            return v[x1][y1];
        }

        int d = (x2 - x1 + 1) / 3;

        vector<int> r(9);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                r[3 * i + j] = DnC(x1 + d * i, y1 + d * j, x1 + d * (i + 1) - 1,
                                   y1 + d * (j + 1) - 1);
            }
        }

        bool isAll0 = true;
        bool isAll1 = true;
        bool isAll2 = true;

        for (int el : r)
        {
            if (el != 0)
                isAll0 = false;
            if (el != 1)
                isAll1 = false;
            if (el != 2)
                isAll2 = false;
        }

        if (isAll0)
            return 0;
        else if (isAll1)
            return 1;
        else if (isAll2)
            return 2;
        else
        {
            for (int el : r)
            {
                if (el < 3)
                {
                    res[el]++;
                }
            }

            return 3;
        }
    };

    if (int r = DnC(0, 0, N - 1, N - 1); r != 3)
        res[r]++;

    for (int el : res)
    {
        cout << el << '\n';
    }

    // inputFileStream.close();
    return 0;
}

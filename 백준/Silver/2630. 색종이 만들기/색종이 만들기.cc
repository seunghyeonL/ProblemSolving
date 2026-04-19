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
        }
    }

    // res[0] : 하양 갯수, res[1] : 파랑 갯수
    vector<int> res(2);

    // 0 : white, 1 : blue, 2 : 섞임
    function<int(int, int, int, int)> DnC = [&](int x1, int y1, int x2,
                                                int y2) -> int
    {
        if (x1 == x2)
        {
            return v[x1][y1];
        }

        int xm = (x1 + x2) / 2;
        int ym = (y1 + y2) / 2;

        int r1 = DnC(x1, y1, xm, ym);
        int r2 = DnC(xm + 1, y1, x2, ym);
        int r3 = DnC(x1, ym + 1, xm, y2);
        int r4 = DnC(xm + 1, ym + 1, x2, y2);

        if (r1 == 0 && r2 == 0 && r3 == 0 && r4 == 0)
            return 0;
        else if (r1 == 1 && r2 == 1 && r3 == 1 && r4 == 1)
            return 1;
        else
        {
            if (r1 != 2)
                res[r1]++;
            if (r2 != 2)
                res[r2]++;
            if (r3 != 2)
                res[r3]++;
            if (r4 != 2)
                res[r4]++;

            return 2;
        }
    };

    if (int r = DnC(0, 0, N - 1, N - 1); r != 2)
        res[r]++;

    cout << res[0] << '\n';
    cout << res[1] << '\n';

    // inputFileStream.close();
    return 0;
}

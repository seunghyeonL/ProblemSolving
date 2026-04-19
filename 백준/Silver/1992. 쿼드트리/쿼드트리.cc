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

    vector<string> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    string black = "0";
    string white = "1";

    // 0 : white, 1 : blue, 2 : 섞임
    function<string(int, int, int, int)> DnC = [&](int x1, int y1, int x2,
                                                   int y2) -> string
    {
        if (x1 == x2 && y1 == y2)
        {
            string res;
            res.push_back(v[x1][y1]);
            return res;
        }

        int xm = (x1 + x2) / 2;
        int ym = (y1 + y2) / 2;

        string r1 = DnC(x1, y1, xm, ym);
        string r2 = DnC(x1, ym + 1, xm, y2);
        string r3 = DnC(xm + 1, y1, x2, ym);
        string r4 = DnC(xm + 1, ym + 1, x2, y2);

        if (r1 == black && r2 == black && r3 == black && r4 == black)
        {
            return black;
        }
        else if (r1 == white && r2 == white && r3 == white && r4 == white)
        {
            return white;
        }
        else
        {
            string res;
            res.push_back('(');
            res += r1;
            res += r2;
            res += r3;
            res += r4;
            res.push_back(')');
            return res;
        }
    };

    cout << DnC(0, 0, N - 1, N - 1) << '\n';
    // inputFileStream.close();
    return 0;
}

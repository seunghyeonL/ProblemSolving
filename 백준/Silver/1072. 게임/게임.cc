#include <bits/stdc++.h>
using namespace std;

long long X, Y;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
     */

    cin >> X >> Y;

    int ans = 0;
    int l = 1, r = 1e9;
    while (l <= r)
    {
        int m = (l + r) / 2;

        if ((Y + m) * 100 / (X + m) > Y * 100 / X)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    cout << (l > 1e9 ? -1 : l);

    // inputFileStream.close();
    return 0;
}
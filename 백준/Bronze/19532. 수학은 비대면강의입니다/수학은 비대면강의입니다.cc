#include <bits/stdc++.h>
using namespace std;    

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    for (int x = -999; x <= 999; x++)
        for (int y = -999; y <= 999; y++)
        {
            if (a * x + b * y == c && d * x + e * y == f)
            {
                cout << x << ' ' << y;
                break;
            }
        }

    // inputFileStream.close();
    return 0;
}
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

    int x_mn = 10000, y_mn = 10000, x_mx = -10000, y_mx = -10000;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;

        x_mn = min(x_mn, x);
        x_mx = max(x_mx, x);
        y_mn = min(y_mn, y);
        y_mx = max(y_mx, y);
    }

    cout << (x_mx - x_mn) * (y_mx - y_mn);

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

map<tuple<int, int, int>, int> memo;

int w(int a, int b, int c)
{
    if (memo.count({a, b, c}))
        return memo[{a, b, c}];

    if (a <= 0 || b <= 0 || c <= 0)
        return memo[{a, b, c}] = 1;

    if (a > 20 || b > 20 || c > 20)
        return memo[{a, b, c}] = w(20, 20, 20);

    if (a < b && b < c)
        return memo[{a, b, c}] =
                   w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

    return memo[{a, b, c}] = w(a - 1, b, c) + w(a - 1, b - 1, c) +
                             w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int a, b, c;
    while (cin >> a >> b >> c)
    {
        if (a == -1 && b == -1 && c == -1)
            break;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c)
             << '\n';
    }

    // inputFileStream.close();
    return 0;
}
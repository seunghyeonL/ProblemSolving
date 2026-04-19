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

    int a, b, c;
    while (cin >> a >> b >> c)
    {
        if (a == 0 && b == 0 && c == 0)
            break;

        if (a + b <= c || b + c <= a || c + a <= b)
            cout << "Invalid";
        else if (a == b && b == c)
            cout << "Equilateral";
        else if (a == b || b == c || c == a)
            cout << "Isosceles";
        else
            cout << "Scalene";

        cout << '\n';
    }
    // inputFileStream.close();
    return 0;
}
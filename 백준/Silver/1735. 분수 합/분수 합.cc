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

    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    int a = a1 * b2 + a2 * b1;
    int b = b1 * b2;

    cout << a / gcd(a, b) << ' ' << b / gcd(a, b);

    // inputFileStream.close();
    return 0;
}
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
    cin >> a >> b >> c;

    if (a + b + c != 180)
        cout << "Error";
    else if (a == 60 && b == 60 && c == 60)
        cout << "Equilateral";
    else if (a == b || b == c || c == a)
        cout << "Isosceles";
    else
        cout << "Scalene";

    // inputFileStream.close();
    return 0;
}
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

    int a1, a2, c, n0;
    cin >> a1 >> a2 >> c >> n0;

    /*
        a1 <= c
        a1 n0 + a2 <= c * n0
    */

    cout << (a1 <= c && a1 * n0 + a2 <= c * n0);

    // inputFileStream.close();
    return 0;
}
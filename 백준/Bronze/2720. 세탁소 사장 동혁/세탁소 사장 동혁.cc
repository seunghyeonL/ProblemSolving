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

    int T;
    cin >> T;

    while (T-- > 0)
    {
        int C;
        cin >> C;

        for (int d : {25, 10, 5, 1})
        {
            cout << C / d << ' ';
            C %= d;
        }
        cout << '\n';
    }

    // inputFileStream.close();
    return 0;
}
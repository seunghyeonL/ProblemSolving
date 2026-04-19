#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
     */

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        if (s1 == s2)
            cout << "Possible" << '\n';
        else
            cout << "Impossible" << '\n';
    }

    // inputFileStream.close();
    return 0;
}
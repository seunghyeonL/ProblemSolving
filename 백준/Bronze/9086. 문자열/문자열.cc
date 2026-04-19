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

    string str;

    while (T-- > 0)
    {
        cin >> str;

        cout << str.front() << str.back() << '\n';
    }

    // inputFileStream.close();
    return 0;
}
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

    /*
     */

    string str;
    cin >> str;

    sort(str.begin(), str.end(), greater<char>());

    cout << str;

    // inputFileStream.close();
    return 0;
}
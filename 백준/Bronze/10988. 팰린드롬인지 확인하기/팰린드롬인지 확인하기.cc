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

    string str;
    cin >> str;

    int sz = str.size();

    int ans = 1;
    for (int i = 0; i < sz / 2; i++)
    {
        if (str[i] != str[sz - 1 - i])
        {
            ans = 0;
            break;
        }
    }

    cout << ans;
    // inputFileStream.close();
    return 0;
}
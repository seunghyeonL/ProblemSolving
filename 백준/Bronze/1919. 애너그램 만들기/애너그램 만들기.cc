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

    string s1, s2;
    cin >> s1 >> s2;

    vector<int> v1(26);
    vector<int> v2(26);

    for (char c : s1)
    {
        v1[c - 'a']++;
    }

    for (char c : s2)
    {
        v2[c - 'a']++;
    }

    int res = 0;
    for (int i = 0; i < 26; i++)
    {
        res += abs(v1[i] - v2[i]);
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
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
        string s;
        cin >> s;

        list<char> li;
        auto cursor = li.end();

        for (char c : s)
        {
            if (c == '<')
            {
                if (cursor != li.begin())
                {
                    --cursor;
                }
            }
            else if (c == '>')
            {
                if (cursor != li.end())
                {
                    ++cursor;
                }
            }
            else if (c == '-')
            {
                if (cursor != li.begin())
                {
                    li.erase(prev(cursor));
                }
            }
            else
            {
                li.insert(cursor, c);
            }
        }

        for (char c : li)
        {
            cout << c;
        }
        cout << '\n';
    }

    // inputFileStream.close();
    return 0;
}
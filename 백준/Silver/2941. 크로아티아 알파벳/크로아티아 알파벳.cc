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
        그리디
    */

    unordered_set<string> us;
    us.insert("c=");
    us.insert("c-");
    us.insert("dz=");
    us.insert("d-");
    us.insert("lj");
    us.insert("nj");
    us.insert("s=");
    us.insert("z=");

    string str;
    cin >> str;

    int len = str.size();

    int res = 0;
    int idx = 0;
    while (idx < len)
    {
        if (idx + 3 - 1 < len && us.count(str.substr(idx, 3)))
        {
            res++;
            idx += 3;
        }
        else if (idx + 2 - 1 < len && us.count(str.substr(idx, 2)))
        {
            res++;
            idx += 2;
        }
        else
        {
            res++;
            idx++;
        }
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}

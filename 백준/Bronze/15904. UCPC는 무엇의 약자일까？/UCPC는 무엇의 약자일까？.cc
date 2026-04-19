#include <bits/stdc++.h>
using namespace std;

string str;
string str_find = "UCPC";

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

    getline(cin, str);

    int idx = 0;
    char need = str_find[idx];
    bool ok = false;
    for (char c : str)
    {
        if (c == need)
        {
            if (++idx == 4)
            {
                ok = true;
                break;
            }
            need = str_find[idx];
        }
    }

    cout << (ok ? "I love UCPC" : "I hate UCPC");

    // inputFileStream.close();
    return 0;
}
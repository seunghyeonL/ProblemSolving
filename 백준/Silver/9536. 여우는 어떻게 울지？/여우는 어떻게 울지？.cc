#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string &str, char delim = ' ')
{
    istringstream iss(str);
    vector<string> res;

    string s;
    while (getline(iss, s, delim))
    {
        res.push_back(s);
    }

    return res;
}

int T;

void solve()
{
    string str;
    getline(cin, str);

    vector<string> sounds(split(str));

    set<string> notFox;

    string line;
    while (getline(cin, line))
    {
        vector<string> spl = split(line);

        if (spl[0] == "what")
            break;

        const string &sound = spl[2];

        notFox.insert(sound);
    }

    for (const string &sound : sounds)
    {
        if (!notFox.count(sound))
            cout << sound << ' ';
    }
    cout << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     */

    // ifstream inputFileStream("input.txt");

    cin >> T;
    cin.ignore(100, '\n');

    for (int i = 0; i < T; i++)
        solve();

    // inputFileStream.close();
    return 0;
}
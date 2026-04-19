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
        set
    */

    int N;
    cin >> N;

    set<string, greater<>> us;

    for (int i = 0; i < N; i++)
    {
        string name, state;
        cin >> name >> state;

        if (state == "enter")
        {
            us.insert(name);
        }
        else if (state == "leave")
        {
            us.erase(name);
        }
    }

    for (const string &name : us)
    {
        cout << name << '\n';
    }

    // inputFileStream.close();
    return 0;
}

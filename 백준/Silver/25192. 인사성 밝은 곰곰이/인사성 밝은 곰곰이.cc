#include <bits/stdc++.h>
using namespace std;

unordered_set<string> us;
int N;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        if (str == "ENTER")
        {
            us.clear();
            continue;
        }

        if (!us.count(str))
        {
            us.insert(str);
            ans++;
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
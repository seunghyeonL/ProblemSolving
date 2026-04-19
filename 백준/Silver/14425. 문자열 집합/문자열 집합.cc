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

    int N, M;
    cin >> N >> M;

    unordered_set<string> us;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        us.insert(str);
    }

    int res = 0;
    for (int j = 0; j < M; j++)
    {
        string str;
        cin >> str;

        if (us.count(str))
        {
            res++;
        }
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}




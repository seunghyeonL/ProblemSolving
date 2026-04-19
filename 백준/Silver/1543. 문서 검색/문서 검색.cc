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

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int N = s1.size();
    int M = s2.size();

    int res = 0;
    auto match = [&](int &idx) -> void
    {
        bool matched = true;
        for (int i = 0; i < M; i++)
        {
            if (s1[idx + i] != s2[i])
            {
                matched = false;
                break;
            }
        }

        if (matched)
        {
            // cout << idx << '!' << '\n';
            res++;
            idx += M;
        }
        else
        {
            idx++;
        }
    };

    for (int i = 0; i < N - M + 1;)
    {
        match(i);
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}

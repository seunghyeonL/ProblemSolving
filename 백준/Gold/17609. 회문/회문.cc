#include <bits/stdc++.h>
using namespace std;

int solve(int l, int r, int diff_cnt, const string &str)
{
    while (l < r)
    {
        if (str[l] != str[r])
        {
            if (diff_cnt == 0)
                return min(solve(l + 1, r, diff_cnt + 1, str), solve(l, r - 1, diff_cnt + 1, str));
            else
                return 2;
        }

        l++, r--;
    }

    return diff_cnt;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int T;
    cin >> T;

    while (--T >= 0)
    {
        string str;
        cin >> str;
        cout << solve(0, str.size() - 1, 0, str) << '\n';
    }

    // inputFileStream.close();
    return 0;
}

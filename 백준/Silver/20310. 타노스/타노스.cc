#include <bits/stdc++.h>
using namespace std;

string S;

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

    cin >> S;
    int sz = S.size();

    vector<bool> rm(sz);

    int cnt_0 = 0, cnt_1 = 0;

    for (char c : S)
    {
        if (c == '0')
            cnt_0++;
        else
            cnt_1++;
    }

    for (int i = 0, cnt_rm = 0; i < sz && cnt_rm < cnt_1 / 2; i++)
    {
        if (S[i] == '1')
        {
            rm[i] = true;
            cnt_rm++;
        }
    }

    for (int i = sz - 1, cnt_rm = 0; i >= 0 && cnt_rm < cnt_0 / 2; i--)
    {
        if (S[i] == '0')
        {
            rm[i] = true;
            cnt_rm++;
        }
    }

    string ans;
    for (int i = 0; i < sz; i++)
    {
        if (!rm[i])
            ans.push_back(S[i]);
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;    

int M;
string str;

// 길이가 len이고 문자가 M개 이하인 부분 문자열이 존재하는가?
bool check(int len)
{
    int freq[128];
    fill(freq, freq + 128, 0);
    int distinct = 0;

    for (int i = 0; i < len; i++)
    {
        if (freq[str[i]]++ == 0)
            distinct++;
    }

    if (distinct <= M)
        return true;

    int sz = str.size();

    for (int i = 0; i < sz - len; i++)
    {
        if (--freq[str[i]] == 0)
            distinct--;

        if (freq[str[i + len]]++ == 0)
            distinct++;

        if (distinct <= M)
            return true;
    }

    return false;
}

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

    while (true)
    {
        cin >> M;
        if (M == 0)
            break;

        cin.ignore(100, '\n');
        getline(cin, str);

        int l = 1, r = str.size();

        while (l <= r)
        {
            int m = (l + r) / 2;

            // upper_bound
            if (check(m))
                l = m + 1;
            else
                r = m - 1;
        }

        cout << r << '\n';
    }

    // inputFileStream.close();
    return 0;
}
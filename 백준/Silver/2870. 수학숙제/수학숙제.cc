#include <bits/stdc++.h>
using namespace std;

bool isNum(char c)
{
    return c >= '0' && c <= '9';
}

bool comp(const string &a, const string &b)
{
    if (a.size() != b.size())
        return a.size() < b.size();

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            return a[i] < b[i];
    }

    return false;
}

void ltrim(string &str)
{
    int nonZeroIdx = -1;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != '0')
        {
            nonZeroIdx = i;
            break;
        }
    }

    if (nonZeroIdx == -1)
        str = "0";
    else
        str = str.substr(nonZeroIdx, str.size() - nonZeroIdx);
}

void parseNum(const string &str, vector<string> &v)
{
    bool isPrevNum = false;

    string buffer;

    for (char c : str)
    {
        if (isPrevNum == true && !isNum(c))
        {
            ltrim(buffer);
            v.push_back(buffer);
            buffer.clear();
            isPrevNum = false;
        }

        if (isNum(c))
        {
            isPrevNum = true;
            buffer.push_back(c);
        }
    }

    if (!buffer.empty())
    {
        ltrim(buffer);
        v.push_back(buffer);
    }
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

    int N;
    cin >> N;

    vector<string> ans;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        parseNum(str, ans);
    }

    sort(ans.begin(), ans.end(), comp);

    for (string el : ans)
    {
        cout << el << '\n';
    }

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    string str1, str2;
    cin >> str1 >> str2;

    int N = str1.size();
    int M = str2.size();

    unordered_map<char, int> idx_str2;
    for (int i = 0; i < M; i++)
        idx_str2[str2[i]] = i;

    // str2의 idx, 현재 str2의 접두사인지 여부
    stack<pair<char, bool>> stk;
    string ans{};

    for (char c : str1)
    {
        if (!idx_str2.count(c))
        {
            stk.emplace(c, false);
            continue;
        }

        // idx_str2.count(c) == true
        int ci = idx_str2[c];
        if (ci == 0)
        {
            if (M > 1)
                stk.emplace(c, true);
            continue;
        }

        // ci > 0
        if (stk.empty())
        {
            stk.emplace(c, false);
            continue;
        }

        // stk.empty() == false
        auto [pc, pb] = stk.top();
        int pi = idx_str2[pc];

        stk.emplace(c, pi + 1 == ci && pb ? true : false);

        if (stk.top().second && ci == M - 1)
        {
            for (int i = 0; i < M; i++)
                stk.pop();
        }
    }

    if (stk.empty())
    {
        cout << "FRULA";
        return 0;
    }

    while (!stk.empty())
    {
        ans.push_back(stk.top().first);
        stk.pop();
    }

    reverse(ans.begin(), ans.end());

    cout << ans;

    // inputFileStream.close();
    return 0;
}
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

    // str2 중복 허용

    string str1, str2;
    cin >> str1 >> str2;

    int N = str1.size();
    int M = str2.size();

    vector<int> F(M);

    for (int i = 1, j = 0; i < M; i++)
    {
        while (j > 0 && str2[i] != str2[j])
            j = F[j - 1];

        if (str2[i] == str2[j])
            F[i] = ++j;
    }

    stack<pair<char, int>> stk;

    for (int i = 0, j = 0; i < N; i++)
    {
        while (j > 0 && str1[i] != str2[j])
            j = F[j - 1];

        if (str1[i] == str2[j])
            ++j;

        stk.emplace(str1[i], j);

        if (j == M)
        {
            for (int k = 0; k < M; k++)
                stk.pop();

            if (stk.empty())
                j = 0;
            else
                j = stk.top().second;
        }
    }

    if (stk.empty())
    {
        cout << "FRULA";
        return 0;
    }

    string ans{};
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
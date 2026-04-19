#include <bits/stdc++.h>

using namespace std;

int c2i(char c)
{
    return c - '0';
}

char i2c(int n)
{
    return '0' + n;
}

void solve()
{
    int N;
    cin >> N;

    vector<vector<int>> trie(N * 10 + 1, vector<int>(10));
    vector<bool> isEndNode(N * 10 + 1);
    int newNodeNum = 1;

    auto insert = [&](const string &str)
    {
        int cur = 0;
        for (char c : str)
        {
            int n = c2i(c);
            if (trie[cur][n] > 0)
            {
                cur = trie[cur][n];
            }
            else
            {
                cur = trie[cur][n] = newNodeNum++;
            }
        }

        isEndNode[cur] = true;
    };

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        insert(str);
    }

    bool isCorrect = true;
    function<void(int)> dfs = [&](int cv)
    {
        if (!isCorrect)
            return;

        for (int nv : trie[cv])
        {
            if (nv == 0)
                continue;

            if (isEndNode[cv])
            {
                isCorrect = false;
                break;
            }

            dfs(nv);
        }
    };

    dfs(0);

    cout << (isCorrect ? "YES" : "NO") << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        트라이
    */

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve();
    }

    // inputFileStream.close();
    return 0;
}

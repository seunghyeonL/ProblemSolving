#include <bits/stdc++.h>
using namespace std;

const int NMX = 10000;
int N, M;
int trie[NMX * 500 + 1][26];
int id;
bool EN[NMX * 500 + 1];

void insert(const string &str)
{
    int cv = 0;

    for (char c : str)
    {
        if (!trie[cv][c - 'a'])
        {
            trie[cv][c - 'a'] = ++id;
        }

        cv = trie[cv][c - 'a'];
    }

    EN[cv] = true;
}

bool isPrefix(const string &str)
{
    bool res = true;
    int cv = 0;
    for (char c : str)
    {
        if (!trie[cv][c - 'a'])
        {
            res = false;
            break;
        }

        cv = trie[cv][c - 'a'];
    }

    return res;
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

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        insert(str);
    }

    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        string str;
        cin >> str;
        if (isPrefix(str))
        {
            ans++;
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
int N;
int trie[NMX * 10 + 1][26];
int id;
int EN[NMX * 10 + 1];

vector<string> prefix;

void insert(const string &nick)
{
    int cv = 0;

    bool foundPrefix = false;
    for (int i = 0; i < nick.size(); i++)
    {
        char c = nick[i];

        if (!trie[cv][c - 'a'])
        {
            trie[cv][c - 'a'] = ++id;
            if (!foundPrefix)
            {
                prefix.push_back(nick.substr(0, i + 1));
                foundPrefix = true;
            }
        }

        cv = trie[cv][c - 'a'];
    }

    EN[cv]++;
    if (!foundPrefix)
    {
        prefix.push_back(nick + (EN[cv] == 1 ? "" : to_string(EN[cv])));
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

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string nick;
        cin >> nick;
        insert(nick);
    }

    for (const string &el : prefix)
    {
        cout << el << '\n';
    }

    // inputFileStream.close();
    return 0;
}
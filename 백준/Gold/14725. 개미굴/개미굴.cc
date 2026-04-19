#include <bits/stdc++.h>
using namespace std;

int node_num;
map<string, int> trie[15 * 1000 + 1];

void insert(const vector<string> &arr)
{
    int cv = 0;
    for (string str : arr)
    {
        if (trie[cv].count(str))
        {
            cv = trie[cv][str];
            continue;
        }

        trie[cv][str] = ++node_num;
        cv = node_num;
    }
}

void print(int cv, int depth)
{
    for (auto [str, nv] : trie[cv])
    {
        // cout << cv << "->" << nv << ": " << str << '\n';

        for (int i = 0; i < depth; i++)
            cout << "--";

        cout << str << '\n';

        print(nv, depth + 1);
    }
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;

        vector<string> arr(n);
        for (int j = 0; j < n; j++)
            cin >> arr[j];

        insert(arr);
    }

    print(0, 0);

    // inputFileStream.close();
    return 0;
}
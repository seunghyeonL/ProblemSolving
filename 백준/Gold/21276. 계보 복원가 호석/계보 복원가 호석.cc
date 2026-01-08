#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000;
unordered_map<string, set<string>> adj;
map<string, int> indeg;

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

    int N, M;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string u;
        cin >> u;

        adj[u] = set<string>();
        indeg[u] = 0;
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        string u, v;
        cin >> u >> v;
        adj[v].insert(u);
        indeg[u]++;
    }

    set<string> roots;
    for (auto [name, deg] : indeg)
    {
        if (deg == 0)
            roots.insert(name);
    }

    cout << roots.size() << '\n';

    for (string name : roots)
    {
        cout << name << ' ';
    }
    cout << '\n';

    for (auto [p, deg] : indeg)
    {
        vector<string> children;
        for (string c : adj[p])
        {
            if (indeg[c] == indeg[p] + 1)
            {
                children.push_back(c);
            }
        }

        cout << p << ' ' << children.size() << ' ';
        for (string c : children)
        {
            cout << c << ' ';
        }
        cout << '\n';
    }

    // inputFileStream.close();
    return 0;
}
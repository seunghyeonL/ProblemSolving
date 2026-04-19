#include <bits/stdc++.h>
using namespace std;
const int NMX = 50;
int N;
int parent[NMX + 1];
vector<int> children[NMX + 1];
int root;

int getLeafNum(int cv)
{
    if (children[cv].size() == 0)
        return 1;

    int res = 0;
    for (int nv : children[cv])
    {
        res += getLeafNum(nv);
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

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int p;
        cin >> p;

        parent[i] = p;

        if (p == -1)
        {
            root = i;
            continue;
        }

        children[p].push_back(i);
    }

    int rm;
    cin >> rm;

    if (rm == root)
    {
        cout << 0 << '\n';
        return 0;
    }

    children[parent[rm]].erase(find(children[parent[rm]].begin(), children[parent[rm]].end(), rm));

    cout << getLeafNum(root) << '\n';

    // inputFileStream.close();
    return 0;
}
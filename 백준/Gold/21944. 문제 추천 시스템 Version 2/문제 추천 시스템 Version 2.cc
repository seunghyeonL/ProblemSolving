#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
const int LGMX = 100;
int N, M;
pair<int, int> probList[NMX + 1]; // 분류, 난이도
map<int, set<int>> lset; // 난이도: 문제번호들
set<pair<int, int>> glset[LGMX + 1]; // 난이도, 문제번호

void add(int p, int l, int g)
{
    probList[p] = {l, g};
    lset[l].insert(p);
    glset[g].emplace(l, p);
}

void solved(int p)
{
    auto [l, g] = probList[p];
    lset[l].erase(p);

    if (lset[l].empty())
        lset.erase(l);

    glset[g].erase({l, p});
}

void recommend1(int g, int x)
{
    if (x == 1)
    {
        cout << prev(glset[g].end())->second << '\n';
    }
    else
    {
        cout << glset[g].begin()->second << '\n';
    }
}

void recommend2(int x)
{
    if (x == 1)
    {
        const set<int> &hardSet = prev(lset.end())->second;
        cout << *prev(hardSet.end()) << '\n';
    }
    else
    {
        const set<int> &easySet = lset.begin()->second;
        cout << *easySet.begin() << '\n';
    }
}

void recommend3(int x, int l)
{
    auto it = lset.lower_bound(l);
    if (x == 1)
    {
        if (it != lset.end())
        {
            const set<int> &targetSet = it->second;
            cout << *targetSet.begin() << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }
    else
    {
        if (it != lset.begin())
        {
            const set<int> &targetSet = prev(it)->second;
            cout << *prev(targetSet.end()) << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
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
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int p, l, g;
        cin >> p >> l >> g;

        add(p, l, g);
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;

        if (s == "recommend")
        {
            int g, x;
            cin >> g >> x;
            recommend1(g, x);
        }
        else if (s == "recommend2")
        {
            int x;
            cin >> x;
            recommend2(x);
        }
        else if (s == "recommend3")
        {
            int x, l;
            cin >> x >> l;
            recommend3(x, l);
        }
        else if (s == "add")
        {
            int p, l, g;
            cin >> p >> l >> g;
            add(p, l, g);
        }
        else if (s == "solved")
        {
            int p;
            cin >> p;
            solved(p);
        }
    }

    // inputFileStream.close();
    return 0;
}
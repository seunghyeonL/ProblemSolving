#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
int N, M;
unordered_map<int, set<P>> m1; // 분류 -> 난이도, 문제번호
map<int, set<int>> m2;         // 난이도 -> 문제번호
unordered_map<int, P> um;      // 문제번호: 분류, 난이도

void recommend1(int g, int x)
{
    if (x == 1)
    {
        cout << prev(m1[g].end())->second << '\n';
    }
    else
    {
        cout << m1[g].begin()->second << '\n';
    }
}

void recommend2(int x)
{
    if (x == 1)
    {
        set<int> hardSet = prev(m2.end())->second;
        cout << *prev(hardSet.end()) << '\n';
    }
    else
    {
        set<int> easySet = m2.begin()->second;
        cout << *easySet.begin() << '\n';
    }
}

void recommend3(int x, int d)
{
    auto it = m2.lower_bound(d);

    if (x == 1)
    {
        if (it == m2.end())
        {
            cout << -1 << '\n';
            return;
        }

        set<int> targetSet = it->second;
        if (targetSet.empty())
        {
            cout << -1 << '\n';
            return;
        }

        cout << *targetSet.begin() << '\n';
    }
    else
    {
        if (it == m2.begin())
        {
            cout << -1 << '\n';
            return;
        }

        set<int> targetSet = prev(it)->second;
        if (targetSet.empty())
        {
            cout << -1 << '\n';
            return;
        }

        cout << *prev(targetSet.end()) << '\n';
    }
}

void add(int p, int d, int g)
{
    m1[g].insert({d, p});
    m2[d].insert(p);
    um.insert({p, {g, d}});
}

void solved(int p)
{
    auto [g, d] = um[p];

    um.erase(p);

    m1[g].erase({d, p});
    if (m1[g].empty())
        m1.erase(g);

    m2[d].erase(p);
    if (m2[d].empty())
        m2.erase(d);
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

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int p, d, g;
        cin >> p >> d >> g;

        add(p, d, g);
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
            int x, d;
            cin >> x >> d;
            recommend3(x, d);
        }
        else if (s == "add")
        {
            int p, d, g;
            cin >> p >> d >> g;
            add(p, d, g);
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
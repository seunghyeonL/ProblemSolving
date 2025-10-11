#include <bits/stdc++.h>
using namespace std;

struct lpData
{
    int l, p;

    bool operator<(const lpData &oper) const
    {
        return l == oper.l ? p < oper.p : l < oper.l;
    }
};

struct glpData
{
    int g, l, p;

    bool operator<(const glpData &oper) const
    {
        return g == oper.g ? (l == oper.l ? p < oper.p : l < oper.l)
                           : g < oper.g;
    }
};

const int NMX = 100000;
const int LGMX = 100;
int N, M;
pair<int, int> probList[NMX + 1]; // 분류, 난이도
set<lpData> lpset;                // 난이도, 문제번호
set<glpData> glpset;              // 분류, 난이도, 문제번호

void add(int p, int l, int g)
{
    probList[p] = {l, g};
    lpset.insert({l, p});
    glpset.insert({g, l, p});
}

void solved(int p)
{
    auto [l, g] = probList[p];
    lpset.erase({l, p});
    glpset.erase({g, l, p});
}

void recommend1(int g, int x)
{
    if (x == 1)
    {
        cout << prev(glpset.upper_bound({g, LGMX, NMX}))->p << '\n';
        //  ({g, })->second << '\n';
    }
    else
    {
        cout << glpset.lower_bound({g, 0, 0})->p << '\n';
    }
}

void recommend2(int x)
{
    if (x == 1)
    {
        cout << prev(lpset.end())->p << '\n';
    }
    else
    {
        cout << lpset.begin()->p << '\n';
    }
}

void recommend3(int x, int l)
{
    auto it = lpset.lower_bound({l, 0});
    if (x == 1)
    {
        if (it != lpset.end())
        {
            cout << it->p << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }
    else
    {
        if (it != lpset.begin())
        {
            cout << prev(it)->p << '\n';
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
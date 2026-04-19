#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int k;
    cin >> k;

    multiset<int> q;

    auto operate = [&](char op, int oper)
    {
        if (op == 'I')
            q.insert(oper);
        else if (op == 'D' && q.size() > 0)
        {
            if (oper == 1)
                q.erase(prev(q.end()));
            else if (oper == -1)
                q.erase(q.begin());
        }
    };

    for (int i = 0; i < k; i++)
    {
        char op;
        int oper;

        cin >> op >> oper;
        operate(op, oper);
    }

    if (q.empty())
        cout << "EMPTY" << '\n';
    else
        cout << *prev(q.end()) << ' ' << *q.begin() << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        multiset
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

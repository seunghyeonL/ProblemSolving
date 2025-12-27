#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        비트마스킹
    */

    int N;
    cin >> N;

    int S = 0;

    auto add = [&](int x)
    {
        S |= 1 << (x - 1);
    };

    auto remove = [&](int x)
    {
        S &= ~(1 << (x - 1));
    };

    auto check = [&](int x)
    {
        cout << (S >> (x - 1) & 1) << '\n';
    };

    auto toggle = [&](int x)
    {
        S ^= 1 << (x - 1);
    };

    auto all = [&]()
    {
        S = ~(1 << 20);
    };

    auto empty = [&]()
    {
        S = 0;
    };

    auto operate = [&](const string &op, int oper)
    {
        if (op == "add")
            add(oper);
        else if (op == "remove")
            remove(oper);
        else if (op == "check")
            check(oper);
        else if (op == "toggle")
            toggle(oper);
        else if (op == "all")
            all();
        else if (op == "empty")
            empty();
    };

    for (int i = 0; i < N; i++)
    {
        string op;
        cin >> op;

        int oper;
        if (op != "all" && op != "empty")
        {
            cin >> oper;
        }

        operate(op, oper);
    }

    // inputFileStream.close();
    return 0;
}

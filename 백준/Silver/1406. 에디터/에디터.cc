#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    list<char> editor;

    string s;
    int N;
    cin >> s >> N;

    auto cursor = editor.end();

    for (char c : s)
    {
        editor.insert(cursor, c);
    }

    auto operate = [&](char op, char oper)
    {
        if (op == 'L' && cursor != editor.begin())
            --cursor;
        else if (op == 'D' && cursor != editor.end())
            ++cursor;
        else if (op == 'B' && cursor != editor.begin())
            editor.erase(prev(cursor));
        else if (op == 'P')
            editor.insert(cursor, oper);
    };

    for (int i = 0; i < N; i++)
    {
        char op{}, oper{};
        cin >> op;
        if (op == 'P')
            cin >> oper;

        operate(op, oper);
    }

    for (auto el : editor)
    {
        cout << el;
    }

    // inputFileStream.close();
    return 0;
}

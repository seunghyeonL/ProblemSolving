#include <bits/stdc++.h>
using namespace std;

int N;
stack<int> st;

void operate(int com, int op = 0)
{
    if (com == 1)
        st.push(op);
    else if (com == 2)
    {
        if (!st.empty())
        {
            cout << st.top() << '\n';
            st.pop();
        }
        else
        {
            cout << -1 << '\n';
        }
    }
    else if (com == 3)
        cout << st.size() << '\n';
    else if (com == 4)
    {
        if (st.empty())
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    else if (com == 5)
    {
        if (!st.empty())
        {
            cout << st.top() << '\n';
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
        int com;
        cin >> com;

        if (com == 1)
        {
            int op;
            cin >> op;
            operate(com, op);
        }
        else
            operate(com);
    }

    // inputFileStream.close();
    return 0;
}
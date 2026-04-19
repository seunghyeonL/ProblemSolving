#include <bits/stdc++.h>
using namespace std;

int N;
queue<int> q;
stack<int> st;

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
        int n;
        cin >> n;
        q.push(n);
    }

    bool ok = true;
    for (int i = 1; i <= N; i++)
    {
        if (!st.empty() && st.top() == i)
        {
            st.pop();
            continue;
        }

        while (!q.empty() && q.front() != i)
        {
            st.push(q.front());
            q.pop();
        }

        if (!q.empty())
        {
            q.pop();
            continue;
        }

        ok = false;
        break;
    }

    cout << (ok ? "Nice" : "Sad");

    // inputFileStream.close();
    return 0;
}
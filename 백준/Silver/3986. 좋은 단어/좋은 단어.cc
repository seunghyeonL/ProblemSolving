#include <bits/stdc++.h>
using namespace std;
int N;
stack<char> st;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*

    */

    cin >> N;
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        bool failed = false;
        for (char c : s)
        {
            if (st.empty())
            {
                st.push(c);
                continue;
            }

            if (st.top() == c)
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }

        if (!st.empty())
        {
            failed = true;
            while (!st.empty())
                st.pop();
        }

        if (!failed)
            answer++;
    }

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}
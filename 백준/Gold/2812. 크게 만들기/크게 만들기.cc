#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    stack<char> st;

    int rmcnt = 0;
    for (char n : s)
    {
        while (!st.empty() && st.top() < n && rmcnt < K)
        {
            st.pop();
            rmcnt++;
        }

        st.push(n);
    }

    while (rmcnt < K)
    {
        st.pop();
        rmcnt++;
    }
    
    string res;
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    reverse(res.begin(), res.end());

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
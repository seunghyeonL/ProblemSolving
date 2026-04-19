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
        역순으로 stack에 넣으면서 자기보다 작거 빼면서 몇개인지 체크
     */

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    stack<int> st;
    vector<int> res(N);

    for (int i = N - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= v[i])
        {
            st.pop();
        }

        res[i] = st.empty() ? -1 : st.top();

        st.push(v[i]);
    }

    for (int el : res)
    {
        cout << el << ' ';
    }
    cout << '\n';

    // inputFileStream.close();
    return 0;
}
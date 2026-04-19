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
     */

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    // 높이, 탑 idx
    stack<pair<int, int>> st;

    vector<int> res(N);

    for (int i = 0; i < N; i++)
    {
        while (!st.empty() && st.top().first < v[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            res[i] = st.top().second + 1;
        }

        st.emplace(v[i], i);
    }

    for (int el : res)
    {
        cout << el << ' ';
    }
    cout << '\n';

    // inputFileStream.close();
    return 0;
}
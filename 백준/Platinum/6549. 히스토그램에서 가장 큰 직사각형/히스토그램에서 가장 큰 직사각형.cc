#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(int N)
{
    vector<int> h(N);
    for (int i = 0; i < N; i++)
        cin >> h[i];

    // height, idx
    stack<pair<int, int>> st;

    ll res = 0;
    for (int i = 0; i < N; i++)
    {
        int curStartIdx = -1;
        while (!st.empty() && st.top().first >= h[i])
        {
            auto [height, idx] = st.top();

            // idx부터 시작하는 height 높이 직사각형 넓이 최댓값
            res = max(res, (ll)(i - idx) * height);

            st.pop();
            curStartIdx = idx;
        }

        st.emplace(h[i], curStartIdx >= 0 ? curStartIdx : i);
    }

    while (!st.empty())
    {
        auto [height, idx] = st.top();

        res = max(res, (ll)(N - idx) * height);

        st.pop();
    }

    cout << res << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
     */

    while (1)
    {
        int N;
        cin >> N;

        if (N == 0)
            break;

        solve(N);
    }

    // inputFileStream.close();
    return 0;
}

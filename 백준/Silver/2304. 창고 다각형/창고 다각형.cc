#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int N;
    cin >> N;

    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i].x;
        cin >> v[i].y;
    }
    sort(v.begin(), v.end());

    // x, y
    stack<pair<int, int>> st;

    int res = 0;
    for (auto [cx, cy] : v)
    {
        if (st.empty())
        {
            st.emplace(cx, cy);
            continue;
        }

        int mxy{};
        int mnx{};
        while (!st.empty() && cy > st.top().y)
        {
            mxy = st.top().y;
            mnx = st.top().x;
            st.pop();
        }

        if (st.empty())
        {
            res += (cx - mnx) * mxy;
        }

        st.emplace(cx, cy);
    }

    while (!st.empty())
    {
        auto [cx, cy] = st.top();
        st.pop();

        if (!st.empty())
        {
            res += (cx - st.top().x) * cy;
        }
        else
        {
            res += cy;
        }
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
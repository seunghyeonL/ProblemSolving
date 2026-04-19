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

    /*
     */

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    // 키, 같은키 흡수한 사이즈
    stack<pair<int, int>> st;

    long long res = 0;
    for (int i = 0; i < N; i++)
    {
        int sameCnt = 1;

        while (!st.empty() && st.top().first <= v[i])
        {
            res += st.top().second;
            if (st.top().first == v[i])
            {
                sameCnt += st.top().second;
            }

            st.pop();
        }

        if (!st.empty())
        {
            res++;
        }

        st.emplace(v[i], sameCnt);
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
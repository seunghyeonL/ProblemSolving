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

    // 높이, 1 + 자기가 관리하는 건물
    stack<pair<int, int>> st;

    long long res = 0;

    for (int i = N - 1; i >= 0; i--)
    {
        int cnt = 1;
        while (!st.empty() && st.top().first < v[i])
        {
            cnt += st.top().second;
            res += st.top().second;
            st.pop();
        }

        st.emplace(v[i], cnt);
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
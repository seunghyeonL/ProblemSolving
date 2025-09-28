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

    string str;
    cin >> str;

    // 괄호, idx
    stack<pair<char, int>> st;
    vector<int> lasers;

    int res = 0;
    for (int i = 0; i < str.size(); i++)
    {
        char cur = str[i];
        if (st.empty())
        {
            st.emplace(cur, i);
            continue;
        }

        if (st.top().first == cur)
        {
            st.emplace(cur, i);
            continue;
        }

        // 항상 올바른 괄호 문자열이 입력이니 괄호가 닫히는 부분
        if (st.top().second == i - 1) // 레이저
        {
            lasers.push_back(i - 1);
            st.pop();
        }
        else // 쇠막대기 끝
        {
            int l = st.top().second;
            int r = i;

            auto it1 = lower_bound(lasers.begin(), lasers.end(), l);
            auto it2 = lower_bound(lasers.begin(), lasers.end(), r);

            int laserCnt = it2 - it1;
            res += laserCnt + 1;

            st.pop();
        }
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}

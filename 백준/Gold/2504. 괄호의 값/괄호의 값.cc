#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    string str;
    cin >> str;

    stack<pair<char, int>> st;

    int res = 0;

    for (char c : str)
    {
        if (c == '(')
        {
            st.push({c, 0});
        }
        else if (c == '[')
        {
            st.push({c, 0});
        }
        else if (c == ')')
        {
            if (st.empty())
            {
                res = 0;
                break;
            }

            auto [tc, tval] = st.top();

            if (tc != '(')
            {
                res = 0;
                break;
            }
            else
            {
                st.pop();

                if (st.empty())
                {

                    res += tval == 0 ? 2 : 2 * tval;
                }
                else
                {
                    st.top().second += tval == 0 ? 2 : 2 * tval;
                }
            }
        }
        else if (c == ']')
        {
            if (st.empty())
            {
                res = 0;
                break;
            }

            auto [tc, tval] = st.top();
            
            if (tc != '[')
            {
                res = 0;
                break;
            }
            else
            {
                st.pop();

                if (st.empty())
                {
                    res += tval == 0 ? 3 : 3 * tval;
                }
                else
                {
                    st.top().second += tval == 0 ? 3 : 3 * tval;
                }
            }
        }
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
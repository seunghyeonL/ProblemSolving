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

    stack<char> st;

    int res = 0;
    for (int i = 0; i < str.size(); i++)
    {
        char cur = str[i];

        if (cur == '(')
            st.push(cur);
        else if (str[i - 1] == '(')
        {
            // 레이저인 경우
            // 현재 스택에 들어있는 '('는 하나빼고 모두 쇠막대기고 모두 잘린다.
            st.pop();
            res += st.size();
        }
        else
        {
            // 쇠막대기인 경우
            // 끝부분이 잘린다. => 하나 증가
            st.pop();
            res++;
        }
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}

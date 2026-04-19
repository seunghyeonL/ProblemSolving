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
    {
        cin >> v[i];
    }

    stack<int> st;
    int n = 1; // 다음에 스택에 넣을 값

    vector<char> res;
    bool isFailed = false;
    for (int el : v)
    {
        if (el >= n) // 찾는 값이 st에 없음
        {
            for (int i = n; i <= el; i++)
            {
                st.push(i);
                res.push_back('+');
            }

            st.pop();
            res.push_back('-');
            n = el + 1;
        }
        else // 찾는 값이 st에 있음
        {
            if (st.top() == el)
            {
                st.pop();
                res.push_back('-');
            }
            else
            {
                isFailed = true;
                break;
            }
        }
    }

    if (isFailed)
    {
        cout << "NO" << '\n';
        return 0;
    }

    for (char c : res)
    {
        cout << c << '\n';
    }

    // inputFileStream.close();
    return 0;
}
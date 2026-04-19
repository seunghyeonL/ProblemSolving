#include <bits/stdc++.h>
using namespace std;
int T;
int N;
int prices[1000000];
stack<int> st; // 주가 idx

void solve()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> prices[i];
    }

    for (int i = 0; i < N; i++)
    {
        while (!st.empty() && prices[st.top()] <= prices[i])
        {
            st.pop();
        }
        st.push(i);
    }

    long long answer = 0;

    while (!st.empty())
    {
        int tidx = st.top();
        st.pop();

        if (st.empty())
        {
            for (int i = 0; i < tidx; i++)
            {
                answer += prices[tidx] - prices[i];
            }
        }
        else
        {
            int lidx = st.top();
            for (int i = lidx + 1; i < tidx; i++)
            {
                answer += prices[tidx] - prices[i];
            }
        }
    }

    cout << answer << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        스택으로 자기보다 작은거 날리면서 압축하고
        그 사이 인덱스들은 구매하기
    */

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve();
    }

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;
string S1, S2;

// dp[i][j] : S1[0, i), S2[0, j) 의 LCS 길이
// dp[i][j]
// S1[i - 1] == S2[j - 1] => dp[i][j] = dp[i - 1][j - 1] + 1
// S1[i - 1] != S2[j - 1] => dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
int dp[MX + 1][MX + 1];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> S1 >> S2;

    int sz1 = S1.size();
    int sz2 = S2.size();

    for (int i = 1; i <= sz1; i++)
    {
        for (int j = 1; j <= sz2; j++)
        {
            if (S1[i - 1] == S2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[sz1][sz2] << '\n';

    stack<char> st;

    int hi = sz1, hj = sz2;

    while (hi > 0 && hj > 0)
    {
        if (S1[hi - 1] == S2[hj - 1])
        {
            st.push(S1[hi - 1]);
            hi--;
            hj--;
        }
        else
        {
            if (dp[hi - 1][hj] < dp[hi][hj - 1])
                hj--;
            else
                hi--;
        }
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }

    // inputFileStream.close();
    return 0;
}
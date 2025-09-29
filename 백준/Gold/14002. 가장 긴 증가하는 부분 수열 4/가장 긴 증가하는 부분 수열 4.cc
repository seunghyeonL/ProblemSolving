#include <bits/stdc++.h>
using namespace std;
int N;
int arr[1001];
int dp[1001];  // dp[i] : i를 끝으로 하는 최대 길이
int pre[1001]; // pre[i] : i를 끝으로 하는 최대 길이의 수열에서 i 앞에 오는 요소
               // idx

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

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        dp[i] = 1;
        pre[i] = i;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
        }
    }

    int mxIdx = max_element(dp, dp + N) - dp;
    cout << dp[mxIdx] << '\n';

    vector<int> history;
    int p = mxIdx;
    while (1)
    {
        history.push_back(p);
        if (pre[p] == p)
            break;
        p = pre[p];
    }

    reverse(history.begin(), history.end());
    for (int idx : history)
    {
        cout << arr[idx] << ' ';
    }
    cout << '\n';

    // inputFileStream.close();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int CMX = 1000;
const int NMX = 20;
int C, N;
int costs[CMX + 1];
int gains[NMX + 1];

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
    cin >> C >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> costs[i];
        cin >> gains[i];
    }

    int mxCost = *max_element(costs + 1, costs + N + 1);

    vector<int> dp(mxCost * CMX + 1);

    // dp[i] : max(dp[i], dp[i - cost[j]] + gain[j]), j : [1, N]

    int answer = 0;
    for (int i = 1; i <= mxCost * CMX + 1; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int cost = costs[j];
            int gain = gains[j];
            if (i >= cost)
                dp[i] = max(dp[i], dp[i - cost] + gain);
        }

        if (dp[i] >= C)
        {
            answer = i;

            break;
        }
    }

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}

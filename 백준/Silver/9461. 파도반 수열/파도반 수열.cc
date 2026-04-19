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

    int T;
    cin >> T;

    vector<long long> dp(101);
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;

    for (int i = 6; i <= 100; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    for (int _ = 0; _ < T; _++)
    {
        int N;
        cin >> N;
        cout << dp[N] << '\n';
    }

    // inputFileStream.close();
    return 0;
}
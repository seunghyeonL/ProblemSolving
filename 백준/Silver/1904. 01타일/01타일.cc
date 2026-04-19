#include <bits/stdc++.h>
using namespace std;

int N;

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
    vector<int> dp(N + 1);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }

    cout << dp[N] << '\n';

    // inputFileStream.close();
    return 0;
}
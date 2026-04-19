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
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    vector<int> dp(N); // dp[i] : arr[i]를 끝으로 하는 최대 연속합
    /*
        dp[i] = max(dp[i - 1] + arr[i], arr[i])
    */

    dp[0] = arr[0];

    for (int i = 1; i < N; i++)
    {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';

    // inputFileStream.close();
    return 0;
}
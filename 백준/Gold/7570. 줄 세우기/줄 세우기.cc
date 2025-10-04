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
        최대로 연속해서 증가하는 수열의 길이 찾기
     */

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    // dp[i] : i를 끝으로 하는 최대 연속 증가 수열 길이
    vector<int> dp(N + 1, 1);
    unordered_set<int> us;

    for (int i = 0; i < N; i++)
    {
        if (us.count(v[i] - 1))
        {
            dp[v[i]] = dp[v[i] - 1] + 1;
        }

        us.insert(v[i]);
    }

    cout << N - *max_element(dp.begin() + 1, dp.end());

    // inputFileStream.close();
    return 0;
}

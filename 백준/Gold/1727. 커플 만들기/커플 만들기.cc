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

    constexpr int INF = 1e9;
    int N, M;
    cin >> N >> M;

    vector<vector<int>> arr(2);
    arr[0].resize(N);
    arr[1].resize(M);

    for (int i = 0; i < N; i++)
        cin >> arr[0][i];

    for (int i = 0; i < M; i++)
        cin >> arr[1][i];

    sort(arr[0].begin(), arr[0].end());
    sort(arr[1].begin(), arr[1].end());

    const auto &arr_b = arr[N <= M];
    const auto &arr_l = arr[N > M];
    int B = arr_b.size();
    int L = arr_l.size();

    // dp[i] : arr_l이랑 arr_b[0, i] 까지 매칭시킬때 성격 차이 합이 최소가 되는 조합
    vector<int> dp[1000];
    dp[L - 1].resize(L);
    iota(dp[L - 1].begin(), dp[L - 1].end(), 0);

    for (int i = L; i < B; i++)
    {
        dp[i] = dp[i - 1];
        vector<int> diff_acc(L + 1);
        for (int j = L - 1; j >= 0; j--)
        {
            int prv = dp[i][j];
            int diff = abs(arr_b[prv + 1] - arr_l[j]) - abs(arr_b[prv] - arr_l[j]);

            if (diff <= 0 && diff_acc[j + 1] + diff <= 0)
            {
                dp[i][j]++;
                diff_acc[j] = 0;
            }
            else
            {
                diff_acc[j] = diff_acc[j + 1] + diff;
            }
        }

        for (int j = 0; j < L - 1; j++)
        {
            if (dp[i][j] == dp[i][j + 1])
                dp[i][j + 1]++;
        }
    }

    int ans = 0;
    for (int j = 0; j < L; j++)
    {
        int bi = dp[B - 1][j];
        ans += abs(arr_b[bi] - arr_l[j]);
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
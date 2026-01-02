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

    vector<int> arr1(N);
    for (int i = 0; i < N; i++)
        cin >> arr1[i];
    vector<int> arr2(M);
    for (int i = 0; i < M; i++)
        cin >> arr2[i];

    // 큰 쪽이 M이 되도록
    if (N > M)
    {
        swap(N, M);
        swap(arr1, arr2);
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    // dp[i][j] : arr1[0...i), arr2[0,,,j)를 매칭하는 최소 비용
    /*
        j를 늘려가면서 j - 1을 매칭하는 경우와 매칭하지 않는 경우를 비교
        dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(arr1[i - 1] - arr2[j - 1]))
    */

    vector<int> prv(M + 1);
    vector<int> cur(M + 1);

    for (int i = 1; i <= N; i++)
    {
        cur[0] = INF;
        for (int j = 1; j <= M; j++)
        {
            cur[j] = min(cur[j - 1], prv[j - 1] + abs(arr1[i - 1] - arr2[j - 1]));
        }
        swap(prv, cur);
    }

    cout << prv[M] << '\n';

    // inputFileStream.close();
    return 0;
}

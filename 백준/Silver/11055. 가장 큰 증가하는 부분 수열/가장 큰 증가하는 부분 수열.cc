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

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    // dp[i] : i를 끝으로 하는 [0, i) 범위의 증가하는 부분 수열 합 최댓값
    // 초기화는 자기 자신으로
    vector<int> dp(v.begin(), v.end());

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[j] < v[i])
            {
                dp[i] = max(dp[i], dp[j] + v[i]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';

    // inputFileStream.close();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<pair<int, int>> items;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int w, c, k;
        cin >> w >> c >> k;

        for (int p = 1; k > 0; p <<= 1)
        {
            int cnt = min(p, k);
            items.push_back({w * cnt, c * cnt});
            k -= cnt;
        }
    }

    // dp[i] : 무게 i로 얻는 최대 만족도
    vector<int> dp(M + 1);

    for (auto [w, c] : items)
    {
        for (int cap = M; cap >= 1; cap--)
        {
            if (cap >= w)
            {
                dp[cap] = max(dp[cap], dp[cap - w] + c);
            }
        }
    }

    cout << dp[M] << '\n';

    // inputFileStream.close();
    return 0;
}

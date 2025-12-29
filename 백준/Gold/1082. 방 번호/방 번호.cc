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

    int N, M;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++)
        cin >> P[i];
    cin >> M;

    vector<string> dp(M + 1); // dp[i] : i원으로 만들 수 있는 최대 숫자

    auto compare = [](const string &a, const string &b)
    { return a.size() == b.size() ? a < b : a.size() < b.size(); };

    // 0 을 마지막에 고려
    for (int n = N - 1; n >= 0; n--)
    {
        int p = P[n];

        for (int cp = p; cp <= M; cp++)
        {
            // dp[j] += dp[j - p];

            const string &prv = dp[cp - p];

            // 앞자리가 0이 되지 않도록
            if (prv.empty() && n == 0)
                continue;

            string tmp{};
            tmp.resize(prv.size() + 1);

            // n이 들어갈 위치
            int lbi = lower_bound(prv.begin(), prv.end(), '0' + n, greater<char>()) - prv.begin();

            copy(prv.begin(), prv.begin() + lbi, tmp.begin());
            tmp[lbi] = '0' + n;
            copy(prv.begin() + lbi, prv.end(), tmp.begin() + lbi + 1);

            dp[cp] = max(dp[cp], tmp, compare);
        }
    }

    string ans = *max_element(dp.begin(), dp.end(), compare);
    cout << (ans.empty() ? "0" : ans);

    // inputFileStream.close();
    return 0;
}


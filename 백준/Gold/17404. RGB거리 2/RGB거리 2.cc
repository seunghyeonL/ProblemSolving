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
    int N;
    cin >> N;

    vector<int> cost_r(N);
    vector<int> cost_g(N);
    vector<int> cost_b(N);

    for (int i = 0; i < N; i++)
    {
        cin >> cost_r[i] >> cost_g[i] >> cost_b[i];
    }

    // dp_c[i] : i idx 집을 c로 칠할때 거기까지 칠하는 최소 비용
    vector<int> dp_r(N);
    vector<int> dp_g(N);
    vector<int> dp_b(N);

    int ans = INF;
    // 첫 집을 r로
    dp_r[0] = cost_r[0];
    dp_g[0] = INF;
    dp_b[0] = INF;

    for (int i = 1; i < N; i++)
    {
        dp_r[i] = min(dp_g[i - 1], dp_b[i - 1]) + cost_r[i];
        dp_g[i] = min(dp_b[i - 1], dp_r[i - 1]) + cost_g[i];
        dp_b[i] = min(dp_r[i - 1], dp_g[i - 1]) + cost_b[i];
    }

    ans = min({ans, dp_g[N - 1], dp_b[N - 1]});

    // 첫 집을 g로
    dp_r[0] = INF;
    dp_g[0] = cost_g[0];
    dp_b[0] = INF;

    for (int i = 1; i < N; i++)
    {
        dp_r[i] = min(dp_g[i - 1], dp_b[i - 1]) + cost_r[i];
        dp_g[i] = min(dp_b[i - 1], dp_r[i - 1]) + cost_g[i];
        dp_b[i] = min(dp_r[i - 1], dp_g[i - 1]) + cost_b[i];
    }

    ans = min({ans, dp_b[N - 1], dp_r[N - 1]});

    // 첫 집을 b로
    dp_r[0] = INF;
    dp_g[0] = INF;
    dp_b[0] = cost_b[0];

    for (int i = 1; i < N; i++)
    {
        dp_r[i] = min(dp_g[i - 1], dp_b[i - 1]) + cost_r[i];
        dp_g[i] = min(dp_b[i - 1], dp_r[i - 1]) + cost_g[i];
        dp_b[i] = min(dp_r[i - 1], dp_g[i - 1]) + cost_b[i];
    }

    ans = min({ans, dp_r[N - 1], dp_g[N - 1]});

    cout << ans;

    // inputFileStream.close();
    return 0;
}

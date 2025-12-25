#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 소는 최대 K마리만 연속한 위치에서 일 할수 있음.

const ll INF = 1e18;
const int NMX = 100000;
int N, K;
ll E[NMX + 2];
ll ps[NMX + 2];

// i소는 일하지 않는 상태에서 [0, i] 범위의 소가 일할때 최대 효율
ll dp[NMX + 2];
// dp[i] = max (dp[i - 1], max j[i - 1 - K, i - 2] {dp[j] + ps[i - 1] - ps[j]})
// dp[i] = max (dp[i - 1], ps[i - 1] + max j[i - 1 - K, i - 2] {dp[j] - ps[j]})

ll get_w(int j)
{
    return dp[j] - ps[j];
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> E[i];

    inclusive_scan(E + 1, E + N + 2, ps + 1);

    // w; 내림차순으로 관리
    deque<ll> dq;

    for (int i = 1; i <= N + 1; i++)
    {
        int j = i - 2;

        if (j >= 0)
        {
            // 덱 맨앞 요소를 최댓값으로
            while (!dq.empty() && get_w(dq.back()) < get_w(j))
                dq.pop_back();

            dq.push_back(j);
        }

        while (!dq.empty() && dq.front() < i - 1 - K)
            dq.pop_front();

        ll w = -INF;
        if (!dq.empty())
            w = get_w(dq.front());

        dp[i] = max(dp[i - 1], ps[i - 1] + w);
    }

    cout << dp[N + 1];

    // inputFileStream.close();
    return 0;
}
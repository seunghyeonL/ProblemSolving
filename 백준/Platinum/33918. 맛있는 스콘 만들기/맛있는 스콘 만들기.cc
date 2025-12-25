#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int NMX = 200;
const int MMX = 25000;
int N, M, C, D;
int B[NMX];

// dp[t][temp] : t초에 temp 온도일때 최대 맛 증가량
ll dp[NMX][MMX + 1];
// dp[i][j] = for k[j - D, j + D], k += C,
// max (dp[i - 1][k] + M - abs(B[i] - j))
// M - abs(B[i] - j) + max(dp[i - 1][k]);

// monotonic queue 활성집합으로 쓰려면 2-pass로
// for k[j - D, j], k += C, M - abs(B[i] - j) + max(dp[i - 1][k]);
// for k[j, j + D], k -= C, M - abs(B[i] - j) + max(dp[i - 1][k]);

ll get_w(int i, int k)
{
    return dp[i - 1][k];
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> M >> C >> D;
    for (int i = 0; i < N; i++)
        cin >> B[i];

    deque<ll> dq;

    for (int j = 1; j <= M; j++)
    {
        dp[0][j] = M - abs(B[0] - j);
    }

    for (int i = 1; i < N; i++)
    {
        for (int r = 0; r < C; r++)
        {
            dq.clear();
            for (int j = 1 + r; j <= M; j += C)
            {
                while (!dq.empty() && get_w(i, dq.back()) < get_w(i, j))
                    dq.pop_back();

                dq.push_back(j);

                while (!dq.empty() && dq.front() < j - D)
                    dq.pop_front();

                dp[i][j] =
                    max(dp[i][j], get_w(i, dq.front()) + M - abs(B[i] - j));
            }

            dq.clear();
            for (int j = M - r; j >= 1; j -= C)
            {
                while (!dq.empty() && get_w(i, dq.back()) < get_w(i, j))
                    dq.pop_back();

                dq.push_back(j);

                while (!dq.empty() && dq.front() > j + D)
                    dq.pop_front();

                dp[i][j] =
                    max(dp[i][j], get_w(i, dq.front()) + M - abs(B[i] - j));
            }
        }
    }

    cout << *max_element(dp[N - 1] + 1, dp[N - 1] + M + 1);

    // inputFileStream.close();
    return 0;
}
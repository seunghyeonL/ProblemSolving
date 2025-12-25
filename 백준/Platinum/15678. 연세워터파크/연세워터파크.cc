#include <bits/stdc++.h>
using namespace std;

// 왼쪽으로 갔다가 오른쪽으로 돌아오는 등의 경로는
// 한 방향으로 가도 만들 수 있는 경로임
// => 방향은 왼쪽으로만 이동

using ll = long long;

const int NMX = 100000;
int N, D;
int arr[NMX];
ll dp[NMX]; // i부터 시작해서 왼쪽으로만 갈때 얻는 점수 최댓값

// dp[i] = for j[i - D, i - 1] max(dp[j] + arr[i]);

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> D;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    // ti; dp[ti] monotonic queue
    deque<int> dq;
    dp[0] = arr[0];
    dq.push_back(0);

    for (int i = 1; i < N; i++)
    {
        while (!dq.empty() && dq.front() < i - D)
            dq.pop_front();

        dp[i] = arr[i];
        if (!dq.empty() && dp[dq.front()] > 0)
            dp[i] += dp[dq.front()];

        while (!dq.empty() && dp[dq.back()] < dp[i])
            dq.pop_back();

        dq.push_back(i);
    }

    cout << *max_element(dp, dp + N);

    // inputFileStream.close();
    return 0;
}
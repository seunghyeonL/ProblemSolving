#include <bits/stdc++.h>
using namespace std;

int N, K;

// n번 뛰었을때의 이동 거리
long long dist(int n)
{
    // cout << (long long)K * n * (n - 1) / 2 << '!' << '\n';
    return (long long)K * n * (n + 1) / 2;
}

void solve()
{
    cin >> N >> K;

    // 뛰는 횟수
    int l = 0, r = N / K;
    while (l <= r)
    {
        int m = (l + r) / 2;

        // 움직인 거리가 N보다 작은가?
        if (dist(m) < N)
            l = m + 1;
        else
            r = m - 1;
    }

    // cout << r << '\n';

    int is_right_end = r % 2;
    int sign = is_right_end ? 1 : -1;
    int x = ((r + 1) / 2 * K - (N - 1 - dist(r))) * sign;

    cout << x << ' ' << (is_right_end ? 'L' : 'R') << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream inputFileStream("input.txt");

    /*
        k * (1 + 2 + 3 + ... + n)
        k * n * (n - 1) / 2

     */
    int T;
    cin >> T;
    while (--T >= 0)
        solve();

    inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> v(2 * N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int i = 0; i < N; i++)
        v[i + N] = v[i];

    // 연속된 구간길이 M의 합이 K 미만인 가짓수 찾기

    int res = 0;

    int sum = accumulate(v.begin(), v.begin() + M, 0);
    
    if (N == M)
    {
        cout << (sum < K) << '\n';
        return;
    }
    
    for (int l = 0, r = M - 1; l < N; l++, r++)
    {
        if (sum < K)
        {
            res++;
        }

        sum += v[r + 1] - v[l];
    }

    cout << res << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*

    */

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
        solve();

    // inputFileStream.close();
    return 0;
}
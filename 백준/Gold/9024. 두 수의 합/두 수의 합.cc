#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000000;
int N, K;
int arr[NMX];

void solve()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    // sum = arr[l] + arr[r]
    // l 증가 => sum 증가
    // r 감소 => sum 감소

    int ans = 1;
    int mn_diff = 1e9;
    int l = 0, r = N - 1;
    while (l < r)
    {
        int sum = arr[l] + arr[r];
        int diff = abs(sum - K);
        if (diff == mn_diff)
            ans++;
        else if (diff < mn_diff)
        {
            ans = 1;
            mn_diff = diff;
        }

        if (sum < K)
            l++;
        else
            r--;
    }

    cout << ans << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int T;
    cin >> T;

    while (--T >= 0)
    {
        solve();
    }

    // inputFileStream.close();
    return 0;
}

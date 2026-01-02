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

    using ll = long long;

    int N, B, C;
    cin >> N >> B >> C;

    vector<ll> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    if (B <= C)
    {
        cout << accumulate(arr.begin(), arr.end(), 0LL) * B;
        return 0;
    }

    // B > C
    ll ans = 0;

    // for (ll n : arr)
    //     cout << n << ' ';
    // cout << '\n';

    for (int i = 0; i < N; i++)
    {
        // cout << "----" << i << "------" << '\n';
        while (arr[i] > 0)
        {
            if (i + 2 < N && arr[i] > 0 && arr[i] <= arr[i + 1] && arr[i + 1] <= arr[i + 2])
            {
                ll n = arr[i];
                ans += n * (B + 2 * C);
                arr[i] -= n;
                arr[i + 1] -= n;
                arr[i + 2] -= n;
                // cout << 3 << ' ' << ans << '\n';
            }
            else if (i + 1 < N && arr[i] > 0 && arr[i] <= arr[i + 1])
            {
                ll n = (i + 2 == N ? arr[i] : min(arr[i], arr[i + 1] - arr[i + 2]));
                ans += n * (B + C);
                arr[i] -= n;
                arr[i + 1] -= n;
                // cout << 2 << ' ' << ans << '\n';
            }
            else
            {
                ll n = (i + 1 == N ? arr[i] : min(arr[i], arr[i] - arr[i + 1]));
                ans += n * B;
                arr[i] -= n;
                // cout << 1 << ' ' << ans << '\n';
            }
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}

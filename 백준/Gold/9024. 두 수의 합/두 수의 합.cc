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

    int ans = 0;
    int mn_diff = 1e9;

    for (int i = 0; i < N - 1; i++)
    {
        int lbi = lower_bound(arr + i + 1, arr + N, K - arr[i]) - arr;

        int cdd1 = abs(arr[i] + arr[lbi - 1] - K);
        int cdd2 = abs(arr[i] + arr[lbi] - K);

        if (lbi - 1 != i)
        {
            if (cdd1 == mn_diff)
            {
                ans++;
            }
            else if (cdd1 < mn_diff)
            {
                ans = 1;
                mn_diff = cdd1;
            }
        }

        if (cdd2 == mn_diff)
        {
            ans++;
        }
        else if (cdd2 < mn_diff)
        {
            ans = 1;
            mn_diff = cdd2;
        }
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

    /*
     */

    int T;
    cin >> T;

    while (--T >= 0)
        solve();

    // inputFileStream.close();
    return 0;
}
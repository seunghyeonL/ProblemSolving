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

    int mn_diff = 1e9 + 1;

    int l = 0, r = N - 1;

    while (l < r)
    {
        int cur = arr[l] + arr[r];
        int diff = abs(cur - K);

        mn_diff = min(mn_diff, diff);

        if (cur < K)
            l++;
        else if (cur > K)
            r--;
        else
        {
            l++;
            r--;
        }
    }

    int mn_cnt = 0;

    l = 0, r = N - 1;
    while (l < r)
    {
        int cur = arr[l] + arr[r];
        int diff = abs(cur - K);

        if (diff > mn_diff)
        {
            if (cur < K)
                l++;
            else
                r--;

            continue;
        }

        // diff == mn_diff;
        if (cur == K)
        {
            if (arr[l] == arr[r])
            {
                mn_cnt += (r - l + 1) * (r - l) / 2;
                break;
            }

            int lv = arr[l];
            int rv = arr[r];
            int cnt_l = 0;
            int cnt_r = 0;

            while (l <= r && arr[l] == lv)
            {
                l++;
                cnt_l++;
            }

            while (l <= r && arr[r] == rv)
            {
                r--;
                cnt_r++;
            }

            mn_cnt += cnt_l * cnt_r;
        }
        else if (cur < K)
        {
            mn_cnt++;
            l++;
        }
        else if (cur > K)
        {
            mn_cnt++;
            r--;
        }
    }

    cout << mn_cnt << '\n';
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
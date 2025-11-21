#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int NMX = 30;
int N, C;

int arr[NMX];

vector<ll> L;
vector<ll> R;

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

    cin >> N >> C;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int half_l = N / 2;
    int half_r = N - half_l;

    // L masking
    for (ll mask = 0; mask < (1 << half_l); mask++)
    {
        ll sum = 0;
        for (int i = 0; i < half_l; i++)
        {
            if ((mask >> i) & 1)
            {
                sum += arr[i];
            }
        }

        L.push_back(sum);
    }
    sort(L.begin(), L.end());

    // R masking
    for (ll mask = 0; mask < (1 << half_r); mask++)
    {
        ll sum = 0;
        for (int i = 0; i < half_r; i++)
        {
            if ((mask >> i) & 1)
            {
                sum += arr[half_l + i];
            }
        }

        R.push_back(sum);
    }
    sort(R.begin(), R.end());

    ll ans = 0;
    for (ll l : L)
    {
        ans += partition_point(R.begin(), R.end(),
                               [l](ll r) { return r + l <= C; }) -
               R.begin();
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
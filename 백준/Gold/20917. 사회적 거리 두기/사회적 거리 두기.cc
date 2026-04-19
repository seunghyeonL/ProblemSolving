#include <bits/stdc++.h>
using namespace std;

const int NMX = 200000;
int N, S;
int arr[NMX];

// 가장 가까운 길이가 mn_len이상이 되도록 S개 이상의 팀을 배치할 수 있는지 여부
bool check(int mn_len)
{
    int len = 0;
    int cnt = 1; // 첫 팀을 arr[0]에 배치

    for (int i = 1; i < N; i++)
    {
        if (len + arr[i] - arr[i - 1] >= mn_len)
        {
            len = 0;
            cnt++;
        }
        else
        {
            len += arr[i] - arr[i - 1];
        }
    }

    // cout << mn_len << ' ' << cnt << '\n';

    if (cnt >= S)
        return true;
    else
        return false;
}

void solve()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    int l = 1, r = 1e9;
    while (l <= r)
    {
        int m = (l + r) / 2;

        if (check(m))
            l = m + 1;
        else
            r = m - 1;
    }

    cout << r << '\n';
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
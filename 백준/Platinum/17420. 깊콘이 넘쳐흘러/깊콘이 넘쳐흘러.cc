#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const int NMX = 100000;
int N;
P arr[NMX]; // 사용 기한, 사용할 날짜

ll get_extend_num(int t1, int t2)
{
    return (t2 - t1 + 30 - 1) / 30;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i].first;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].second;
    }

    // 사용할 날짜가 작은 순서
    sort(arr, arr + N,
         [](const P &a, const P &b)
         {
             return a.second == b.second ? a.first < b.first
                                         : a.second < b.second;
         });

    ll ans = 0;

    // 쿠폰의 사용기간을 사용일보다 늦도록 연장
    for (int i = 0; i < N; i++)
    {
        auto &[et, ut] = arr[i];

        if (et < ut)
        {
            ll n = get_extend_num(et, ut);
            ans += n;
            et += 30 * n;
        }
    }

    // 사용 기간이 비내림차순이 되도록 연장해주기
    // 단, 같은 날에 사용하는 애들은 내림차순이어도 괜찮음
    for (ll i = 0, et_mx = 0, p_et_mx = 0, p_ut = 0; i < N; i++)
    {
        auto &[et, ut] = arr[i];

        if (p_ut < ut)
        {
            p_ut = ut;
            p_et_mx = et_mx;
        }

        if (et < p_et_mx)
        {
            ll n = get_extend_num(et, p_et_mx);
            ans += n;
            et += 30 * n;
        }

        et_mx = max(et_mx, et);
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
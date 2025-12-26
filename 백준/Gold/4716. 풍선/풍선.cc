#include <bits/stdc++.h>
using namespace std;

// A, B중 먼 곳에서 풍선을 받을때 거리 손해는
// abs(db - da)
// 거리 손해가 큰 팀부터 가까운 곳에서 가까운 곳에서 배정

const int NMX = 1000;
int N;
int Na, Nb;
tuple<int, int, int> arr[NMX]; // 필요 풍선수, A 거리, B 거리

void solve()
{
    for (int i = 0; i < N; i++)
    {
        int k, da, db;
        cin >> k >> da >> db;

        arr[i] = {k, da, db};
    }

    // 먼 곳에서 배정 받을때 손해가 큰 순으로 정렬
    sort(arr, arr + N,
         [](const auto &x, const auto &y)
         {
             const auto &[kx, dax, dbx] = x;
             const auto &[ky, day, dby] = y;

             return abs(dax - dbx) > abs(day - dby);
         });

    long long ans = 0;

    for (int i = 0; i < N; i++)
    {
        auto [k, da, db] = arr[i];

        int d1 = (da < db ? da : db);
        int d2 = (da < db ? db : da);
        int &s1 = (da < db ? Na : Nb);
        int &s2 = (da < db ? Nb : Na);

        while (--k >= 0)
        {
            if (s1 > 0)
            {
                --s1;
                ans += d1;
            }
            else
            {
                --s2;
                ans += d2;
            }
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

    while (cin >> N >> Na >> Nb)
    {
        if (N == 0)
            break;

        solve();
    }

    // inputFileStream.close();
    return 0;
}
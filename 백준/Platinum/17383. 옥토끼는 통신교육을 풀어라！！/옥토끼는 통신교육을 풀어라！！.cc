#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int N;
vector<ll> T;

// 모든 문제풀이 사이 간격이 mx_t 이하인가?
// lmt >= ans -> true
// lmt < ans -> false

bool check(ll mx_t)
{
    ll t1 = 0;   // 이전 문제 푼 시간 1
    ll t2 = 0;   // 이전 문제 푼 시간 2
    int cnt = 0; // 푼 문제 개수

    int l = 0, r = N - 1;

    // 문제풀이 간격을 mx_t보다 작도록
    // 가능한 큰 문제부터 배정
    while (cnt < N)
    {
        if (t1 > t2)
            swap(t1, t2);

        // t1 <= t2

        int ti{}; // 이번에 풀 문제 idx

        // mx_t 이하의 문제를 t1에서 풀어야함
        if (t2 - t1 > mx_t)
        {
            if (T[l] > mx_t)
                break;

            ti = l++;
        }
        else // t1에서 더 긴 시간의 문제를 풀어도 됨
        {
            ti = r--;
        }

        t1 += T[ti];
        if (t1 % mx_t)
            t1 += mx_t - t1 % mx_t;

        cnt++;

        // if (mx_t == 5)
        // {
        //     cout << t1 << ' ' << t2 << '\n';
        // }
    }

    if (cnt == N)
        return true;
    else
        return false;
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
    T.resize(N);

    for (int i = 0; i < N; i++)
        cin >> T[i];

    sort(T.begin(), T.end());

    ll l = *min_element(T.begin(), T.end());
    ll r = *max_element(T.begin(), T.end());

    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (check(m))
            r = m - 1;
        else
            l = m + 1;
    }

    cout << l << '\n';

    // inputFileStream.close();
    return 0;
}
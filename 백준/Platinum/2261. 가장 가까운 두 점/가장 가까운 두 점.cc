#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
using ll = long long;

const ll INF = 1e18;
const int NMX = 100000;
int N;
P arr[NMX];
P tmp[NMX];

bool comp_y(const P &a, const P &b)
{
    auto [ax, ay] = a;
    auto [bx, by] = b;

    return ay < by;
}

ll square(ll n)
{
    return n * n;
}

ll get_dist(const P &a, const P &b)
{
    return square(b.first - a.first) + square(b.second - a.second);
}

ll DnC(int l, int r)
{
    if (l == r)
        return INF;

    int m = (l + r) / 2;
    auto [xm, ym] = arr[m];
    
    // 좌우 분할정복
    ll d = min(DnC(l, m), DnC(m + 1, r));

    // 구간 y에 대한 오름차순으로 정렬
    merge(arr + l, arr + m + 1, arr + m + 1, arr + r + 1, tmp + l, comp_y);
    copy(tmp + l, tmp + r + 1, arr + l);

    vector<P> cand;

    for (int i = l; i <= r; i++)
    {
        if (square(arr[i].first - xm) < d)
            cand.push_back(arr[i]);
    }

    int sz = cand.size();

    for (int i = 1; i < sz; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (square(cand[i].second - cand[j].second) >= d)
                break;

            d = min(d, get_dist(cand[i], cand[j]));
        }
    }

    return d;
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
        x 중간값 기준으로 오른쪽 최소거리, 왼쪽 최소거리, 교차 최소거리 비교
       분할정복
     */

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;

        arr[i] = {x, y};
    }

    sort(arr, arr + N);

    ll ans = DnC(0, N - 1);
    cout << (ans == INF ? 0 : ans);

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int N, M;
    cin >> N >> M;

    // 출발지, 도착지, 노선번호
    vector<tuple<ll, ll, int>> arr;

    for (int i = 1; i <= M; i++)
    {
        ll u, v;
        cin >> u >> v;
        if (u > v)
            v += N;

        // 환형이라 각 정류장마다 모든 경우를 체크하기 위해 두바퀴 돌리기
        arr.emplace_back(u, v, i);
        arr.emplace_back(u + N, v + N, i);
    }

    // 출발점 기준 오름차순 -> 도착점 내림차순
    sort(arr.begin(), arr.end(),
         [](const auto &a, const auto &b)
         {
             auto &[au, av, an] = a;
             auto &[bu, bv, bn] = b;

             return au == bu ? av > bv : au < bu;
         });

    vector<bool> erased(M + 1);

    // 지금 이미 커버되는 가장 먼 끝점
    ll mx_v = -1;

    for (auto [u, v, i] : arr)
    {
        if (mx_v >= v)
            erased[i] = true;
        else
            mx_v = v;
    }

    for (int i = 1; i <= M; i++)
        if (!erased[i])
            cout << i << ' ';

    // inputFileStream.close();
    return 0;
}

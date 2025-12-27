#include <bits/stdc++.h>
using namespace std;

int N, M;

vector<pair<int, int>> arr; // 가격, 무게
vector<int> S;              // S[i] : sum arr[0, i].second ; 무게 누적합
vector<int> P;              // P[i] : i번째 물건까지 얻을때 가격

// 가격 오름차순 -> 무게 내림차순 정렬 (같은 가격이면 더 큰 무게부터 사야함)
// 앞에서부터 쭉 챙기면 되는데 중복이 있는 경우는 가격 계산을
// 따로 고려해줘야함

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> M;
    arr.resize(N);
    S.resize(N);
    P.resize(N);

    for (int i = 0; i < N; i++)
    {
        int w, p;
        cin >> w >> p;
        arr[i] = {p, w};
    }

    sort(arr.begin(), arr.end(),
         [](const auto &a, const auto &b)
         {
             auto &[ap, aw] = a;
             auto &[bp, bw] = b;

             return ap == bp ? aw > bw : ap < bp;
         });

    S[0] = arr[0].second;
    for (int i = 1; i < N; i++)
        S[i] = S[i - 1] + arr[i].second;

    if (S[N - 1] < M)
    {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0, cp = -1; i < N; i++)
    {
        const auto &[p, w] = arr[i];

        // 새로운 가격 구간 시작
        if (p > cp)
        {
            P[i] = p;
            cp = p;
            continue;
        }

        // p == cp
        P[i] = P[i - 1] + p;
    }

    // 가능한 최소 무게 덩어리 idx
    int lbi = lower_bound(S.begin(), S.end(), M) - S.begin();

    // 이 무게 이상 얻는 가격이 가장 작은 덩어리 찾기
    int ans = *min_element(P.begin() + lbi, P.end());
    cout << ans;

    // inputFileStream.close();
    return 0;
}
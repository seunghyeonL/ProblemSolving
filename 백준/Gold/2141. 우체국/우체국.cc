#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int NMX = 100000;
int N;
vector<pair<int, int>> arr; // 마을 위치, 사람 수

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    // 최적의 경우는 우체국을 마을에 설치하는 경우이다 (귀류법)
    // 현재 마을 포함 왼쪽의 마을 의 사람 수가 오른쪽 사람수보다 작을때
    // 오른쪽으로 이동

    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr.begin(), arr.end());

    // 우체국이 첫 마을일때 상황
    int px = arr[0].first;
    ll N_l = arr[0].second;
    ll N_r = accumulate(arr.begin() + 1, arr.end(), 0LL,
                        [](const ll &acc, const auto &cur)
                        { return acc + cur.second; });

    // 우체국 오른쪽 마을로 하나씩 이동
    for (int i = 1; i < N; i++)
    {
        if (N_l >= N_r)
            break;

        const auto &[cx, cn] = arr[i];

        N_l += cn;
        N_r -= cn;
        px = cx;
    }

    cout << px;

    // inputFileStream.close();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000;
const int WMX = 1000;
int N, W;

pair<int, int> arr[WMX + 2];

// car의 위치를 {0, 0}, {N, N}을 포함한 사건 발생 위치 idx로 표현
// memo[car1_pos_i][car2_pos_i] == dist
int memo[WMX + 2][WMX + 2];
int car_num[WMX + 2][WMX + 2];
pair<int, int> nxt[WMX + 2][WMX + 2];

int get_dist(int c1, int c2)
{
    auto [x1, y1] = arr[c1];
    auto [x2, y2] = arr[c2];

    return abs(x2 - x1) + abs(y2 - y1);
}

// wi idx 사건을
// 경찰차 c1, c2 위치에서 맞이했을때 이후 마지막 사건을 해결할때까지의 최소
// 이동거리
int rec(int c1, int c2)
{
    if (memo[c1][c2])
        return memo[c1][c2];

    int wi = max(c1, c2) + 1;

    if (wi == W + 2)
        return 0;

    int d1 = rec(wi, c2) + get_dist(c1, wi);
    int d2 = rec(c1, wi) + get_dist(c2, wi);

    if (d1 < d2)
    {
        car_num[c1][c2] = 1;
        nxt[c1][c2] = {wi, c2};
        return memo[c1][c2] = d1;
    }
    else
    {
        car_num[c1][c2] = 2;
        nxt[c1][c2] = {c1, wi};
        return memo[c1][c2] = d2;
    }
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> W;
    arr[0] = {1, 1};
    arr[1] = {N, N};

    for (int i = 2; i < W + 2; i++)
    {
        int x, y;
        cin >> x >> y;

        arr[i] = {x, y};
    }

    cout << rec(0, 1) << '\n';

    int hc1 = 0, hc2 = 1;

    while (car_num[hc1][hc2])
    {
        cout << car_num[hc1][hc2] << '\n';
        tie(hc1, hc2) = nxt[hc1][hc2];
    }

    // inputFileStream.close();
    return 0;
}
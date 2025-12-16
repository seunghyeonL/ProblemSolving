#include <bits/stdc++.h>
using namespace std;

/*
    w : 가로 세로 이동 코스트
    s : 대각 이동 코스트

    w >= s => 항상 대각으로 이동, 그런데 mx - mn이 홀수면 한번은 가로세로이동
   해야함 w < s && s < 2 * w => x, y 좌표중 하나가 목적지와 같아질때 까지 대각,
   이후 가로세로 s >= 2 * w => 항상 가로세로로 이동
*/

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int x, y, w, s;
    cin >> x >> y >> w >> s;

    long long mx = max(x, y);
    long long mn = min(x, y);

    long long ans = min({mn * s + (mx - mn) / 2 * 2 * s + (mx - mn) % 2 * w,
                         (mx + mn) * w, mn * s + (mx - mn) * w});

    cout << ans;

    // inputFileStream.close();
    return 0;
}


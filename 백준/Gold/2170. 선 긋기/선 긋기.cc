#include <bits/stdc++.h>
using namespace std;

int N;
// 좌표, 선 시작/끝 여부
// 0 : 시작, 1 : 끝
pair<int, int> events[2000001];

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

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int l, r;
        cin >> l >> r;

        events[2 * i] = {l, 0};
        events[2 * i + 1] = {r, 1};
    }

    sort(events, events + 2 * N);

    int res = 0;

    auto [x0, t0] = events[0];
    int curLineCnt = 1;
    int px = x0;
    for (int i = 1; i < 2 * N; i++)
    {
        auto [cx, ct] = events[i];
        if (curLineCnt > 0)
        {
            res += cx - px;
        }

        px = cx;

        if (ct == 0)
        {
            curLineCnt++;
        }
        else
        {
            curLineCnt--;
        }
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
const int LMT = 100000;
int M, N, L;

P target[LMT];
int s_pos[LMT];

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

    cin >> M >> N >> L;

    for (int i = 0; i < M; i++)
        cin >> s_pos[i];

    for (int i = 0; i < N; i++)
    {
        cin >> target[i].first;
        cin >> target[i].second;
    }

    sort(s_pos, s_pos + M);
    sort(target, target + N);

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        auto [tx, ty] = target[i];

        int spi = lower_bound(s_pos, s_pos + M, tx) - s_pos;

        if (spi < M && s_pos[spi] - tx + ty <= L)
            ans++;
        else if (spi > 0 && tx - s_pos[spi - 1] + ty <= L)
            ans++;
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
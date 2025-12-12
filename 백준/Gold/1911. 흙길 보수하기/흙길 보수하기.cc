#include <bits/stdc++.h>
using namespace std;

using E = pair<int, bool>; // pos, is_start

const int NMX = 10000;
int N, L;

vector<E> puddle;

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

    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        int s, e;
        cin >> s >> e;

        puddle.emplace_back(s, true);  // 시작점
        puddle.emplace_back(e, false); // 끝점
    }

    // 좌표값이 작은 순서, end가 start보다 우선
    sort(puddle.begin(), puddle.end());

    int ans = 0;
    int cx = 0; // 덮기 시작할 위치
    for (auto [x, is_start] : puddle)
    {
        if (is_start)
        {
            cx = max(cx, x);
        }
        else
        {
            int n = (x - cx + L - 1) / L;
            ans += n;
            cx += L * n;
        }
    }

    cout << ans << '\n';

    // inputFileStream.close();
    return 0;
}
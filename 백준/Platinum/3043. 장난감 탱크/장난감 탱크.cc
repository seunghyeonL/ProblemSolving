#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");
    int N;
    cin >> N;

    // x좌표, y좌표, 탱크번호
    vector<tuple<int, int, int>> t_pos(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int x, y;
        cin >> x >> y;
        t_pos[i] = {x, y, i};
    }

    int ans = 0;
    vector<pair<int, char>> his;

    // 정렬 후 행이동
    sort(t_pos.begin() + 1, t_pos.end());

    // 위로이동
    for (int i = 1; i <= N; i++)
    {
        auto &[x, y, n] = t_pos[i];

        while (x > i)
        {
            x--;
            ans++;
            his.emplace_back(n, 'U');
        }
    }

    // 아래로 이동
    for (int i = N; i >= 1; i--)
    {
        auto &[x, y, n] = t_pos[i];

        while (x < i)
        {
            x++;
            ans++;
            his.emplace_back(n, 'D');
        }
    }

    // 열 정렬하고 열이동
    sort(t_pos.begin() + 1, t_pos.end(),
         [](const auto &a, const auto &b)
         {
             auto [ax, ay, an] = a;
             auto [bx, by, bn] = b;

             return ay == by ? ax < bx : ay < by;
         });

    // 왼쪽이동
    for (int i = 1; i <= N; i++)
    {
        auto &[x, y, n] = t_pos[i];

        while (y > i)
        {
            y--;
            ans++;
            his.emplace_back(n, 'L');
        }
    }

    // 오른쪽이동
    for (int i = N; i >= 1; i--)
    {
        auto &[x, y, n] = t_pos[i];

        while (y < i)
        {
            y++;
            ans++;
            his.emplace_back(n, 'R');
        }
    }

    cout << ans << '\n';
    for (auto [i, c] : his)
    {
        cout << i << ' ' << c << '\n';
    }

    // inputFileStream.close();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

constexpr int NMX = 100;
int N;
int board[2][NMX];

int get_mine_num(vector<int> &v)
{
    for (int i = 1; i < N - 1; i++)
    {
        int need = board[0][i];
        int cur = v[i - 1] + v[i];

        if (need - cur >= 2 || need - cur < 0)
            return -1;

        if (board[1][i + 1] == 1 && need - cur != 1)
            return -1;

        v[i + 1] = need - cur;

        // for (int n : v)
        //     cout << n << ' ';
        // cout << '\n';
    }

    if (board[0][N - 1] != v[N - 2] + v[N - 1])
        return -1;

    return accumulate(v.begin(), v.end(), 0);
}

void solve()
{
    cin >> N;

    {
        string line1, line2;
        cin >> line1 >> line2;
        for (int i = 0; i < N; i++)
        {
            int n = line1[i] - '0';
            board[0][i] = n;
        }

        for (int i = 0; i < N; i++)
        {
            char c = line2[i];
            if (c == '*')
                board[1][i] = 1;
            else
                board[1][i] = 0;
        }
    }

    if (N == 1)
    {
        if (board[0][0] == '0')
            cout << 0 << '\n';
        else
            cout << 1 << '\n';

        return;
    }

    vector<int> v(N);
    // 왼쪽 두개가 결정되면 오른쪽도 결정됨

    int ans = 0;

    // 시작이 0일때
    if (board[0][0] == 0)
    {
        v[0] = 0;
        v[1] = 0;
        ans = max(ans, get_mine_num(v));
    }

    // 시작이 1일때
    if (board[0][0] == 1)
    {
        if (board[1][1] != 1)
        {
            fill(v.begin(), v.end(), 0);
            v[0] = 1;
            v[1] = 0;
            ans = max(ans, get_mine_num(v));
        }

        if (board[1][0] != 1)
        {
            fill(v.begin(), v.end(), 0);
            v[0] = 1;
            v[1] = 0;
            ans = max(ans, get_mine_num(v));
        }
    }

    if (board[0][0] == 2)
    {
        fill(v.begin(), v.end(), 0);
        v[0] = 1;
        v[1] = 1;
        ans = max(ans, get_mine_num(v));
    }

    cout << ans << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int T;
    cin >> T;

    while (--T >= 0)
        solve();

    // inputFileStream.close();
    return 0;
}
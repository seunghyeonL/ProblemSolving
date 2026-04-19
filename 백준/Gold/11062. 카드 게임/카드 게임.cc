#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000;
int N;
int arr[NMX];

// memo[l][r][turn] : arr[l, r], turn 에 근우가 얻을 수 있는 최대 점수
int memo[NMX][NMX][2];

void reset()
{
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < N ; j++)
        {
            memo[i][j][0] = 0;
            memo[i][j][1] = 0;
        }
}


void rec(int l, int r, int turn)
{
    if (memo[l][r][turn])
        return;
    
    if (l == r)
    {
        if (turn == 0)
            memo[l][r][turn] = arr[l];
        return;
    }

    rec(l + 1, r, (turn + 1) % 2);
    rec(l, r - 1, (turn + 1) % 2);

    if (turn == 0)
        memo[l][r][0] = max(arr[l] + memo[l + 1][r][1], arr[r] + memo[l][r - 1][1]);
    else
        memo[l][r][1] = min(memo[l + 1][r][0], memo[l][r - 1][0]);
}

void solve()
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    reset();
    
    rec(0, N - 1, 0);

    cout << memo[0][N - 1][0] << '\n';
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

    while (T-- > 0)
        solve();

    // inputFileStream.close();
    return 0;
}
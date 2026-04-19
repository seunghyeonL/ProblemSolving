#include <bits/stdc++.h>
using namespace std;

const int NMX = 100;
const int CMX = 100;
const int XMX = 10000;
int N, X;
vector<int> pipes;

// dp[i] : i 길이를 만들 수 있는 방법 수
int dp_prev[XMX + 1], dp_next[XMX + 1];

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

    cin >> N >> X;
    dp_prev[0] = 1;
    dp_next[0] = 1;

    for (int i = 0; i < N; i++)
    {
        int L, C;
        cin >> L >> C;

        copy(dp_next, dp_next + XMX + 1, dp_prev);

        for (int idx = 0; idx <= X; idx++)
        {
            if (dp_prev[idx] == 0)
                continue;

            for (int cnt = 1; cnt <= C; cnt++)
            {
                if (idx + cnt * L > X)
                    break;

                dp_next[idx + cnt * L] += dp_prev[idx];
            }
        }

        // for (int i = 0; i <= X; i++)
        //     cout << dp_next[i] << ' ';
        // cout << '\n';
    }

    cout << dp_next[X];

    // inputFileStream.close();
    return 0;
}
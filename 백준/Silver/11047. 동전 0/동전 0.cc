#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        greedy
        큰 거부터 쓰기
    */

    int N, K;
    cin >> N >> K;

    vector<int> coins(N);

    for (int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }

    int res = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        int coin = coins[i];

        res += K / coin;

        K %= coin;
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
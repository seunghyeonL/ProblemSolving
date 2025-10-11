
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int N;
    cin >> N;

    int cnt = 0;
    while (true)
    {
        if ((cnt + 1) * (cnt + 1) <= N)
            cnt++;
        else
            break;
    }

    cout << cnt << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        [1, N]범위 약수의 개수가 홀수인 수 갯수
        <=> [1, N]범위 제곱수 갯수
     */

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve();
    }

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int N;
    cin >> N;

    vector<int> v(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
    }

    // dp1[i] : i번째 계단에서 계단을 밟을 수 있을 때 [1, i]에서 얻을 수 있는 최대 점수
    // dp2[i] : i번째 계단에서 다음 계단을 밟을 수 없을 때 [1, i]에서 얻을 수 있는 최대 점수
    vector<int> dp1(N + 1);
    vector<int> dp2(N + 1);
    dp1[1] = v[1];
    dp1[2] = v[2];

    dp2[2] = v[1] + v[2]; // 다음 계단 x

    dp1[3] = v[1] + v[3]; // 다음 계단 o
    dp2[3] = v[2] + v[3]; // 다음 계단 x

    // dp1[i] = dp2[i - 2] + v[i]; -> 다음 계단 ok
    // dp2[i] = dp1[i - 1] + v[i]; -> 다음 계단 불가

    for (int i = 4; i <= N; i++)
    {
        dp1[i] = max(dp1[i - 2] + v[i], dp2[i - 2] + v[i]);
        dp2[i] = dp1[i - 1] + v[i];
    }

    cout << max(dp1[N], dp2[N]) << '\n';
    // inputFileStream.close();
    return 0;
}
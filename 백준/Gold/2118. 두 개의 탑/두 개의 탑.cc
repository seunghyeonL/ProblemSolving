#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    // 범위를 두배로 붙여서 S/2를 딱 넘는 순간까지 가고 그거 한칸 앞꺼랑 같이
    // 체크

    int N;
    cin >> N;

    vector<int> v(2 * N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < N; i++)
    {
        v[i + N] = v[i];
    }

    int S = accumulate(v.begin(), v.begin() + N, 0);

    int res = 0;
    for (int l = 0, r = 0, sum = 0; l < N && r < 2 * N; l++)
    {
        while (r <= l + N && sum + v[r] <= S / 2)
        {
            sum += v[r++];
        }

        res = max(res, sum);
        if (r <= l + N)
        {
            res = max(res, S / 2 - sum - v[r]);
        }

        sum -= v[l];
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}

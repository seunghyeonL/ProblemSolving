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

    */

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int X;
    cin >> X;

    long long ans = 0;
    int l = 0, r = N - 1;
    while (l < r)
    {
        int sum = v[l] + v[r];

        if (v[l] == v[r])
        {
            if (sum == X)
            {
                ans += (long long)(r - l + 1) * (r - l) / 2;
            }

            break;
        }

        int cnt_l = 1;
        int cnt_r = 1;

        while (v[l + cnt_l] == v[l])
            cnt_l++;

        while (v[r + cnt_r] == v[r])
            cnt_r++;

        if (sum < X)
            l += cnt_l;
        else if (sum > X)
            r -= cnt_r;
        else
        {
            ans += (long long)cnt_l * cnt_r;
            l += cnt_l;
            r -= cnt_r;
        }
    }

    cout << ans << '\n';

    // inputFileStream.close();
    return 0;
}
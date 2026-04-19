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
        l++ -> v[l] + v[r] 증가
        r-- -> v[l] + v[r] 감소
     */

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int res1{}, res2{};
    int mn = 2 * 1e9 + 10;

    int l = 0, r = N - 1;
    while (l < r)
    {
        if (mn >= abs(v[l] + v[r]))
        {
            mn = abs(v[l] + v[r]);
            res1 = v[l];
            res2 = v[r];
        }

        if (v[l] + v[r] > 0)
        {
            r--;
        }
        else if (v[l] + v[r] < 0)
        {
            l++;
        }
        else
        {
            break;
        }
    }

    cout << res1 << ' ' << res2 << '\n';

    // inputFileStream.close();
    return 0;
}

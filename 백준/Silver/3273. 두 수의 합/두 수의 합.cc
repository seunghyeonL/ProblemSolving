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

    long long res = 0;
    int l = 0, r = N - 1;
    while (l < r)
    {
        if (v[l] + v[r] == X)
        {
            if (v[l] == v[r])
            {
                int cnt = r - l + 1;
                res += (long long)cnt * (cnt - 1) / 2;
                break;
            }
            else
            {
                int lcnt = 1;
                int rcnt = 1;
                while (v[l + 1] == v[l])
                {
                    l++;
                    lcnt++;
                }
                while (v[r - 1] == v[r])
                {
                    r--;
                    rcnt++;
                }

                res += (long long)lcnt * rcnt;

                l++;
                r--;
            }
        }
        else if (v[l] + v[r] < X)
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}
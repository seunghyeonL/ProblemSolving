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

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    // 하나를 고정
    // O(N)
    // 투포인터(양끝좁히기) or 이분탐색
    // O(N^2) or O(N^2logN)

    long long res = 0;
    for (int i = 0; i < N - 2; i++)
    {
        int l = i + 1, r = N - 1;
        int need = -v[i];
        while (l < r)
        {
            if (v[l] + v[r] == need)
            {
                if (v[l] == v[r])
                {
                    res += (r - l + 1) * (r - l) / 2;
                    break;
                }
                else
                {
                    int lv = v[l];
                    int rv = v[r];
                    int lcnt = 0;
                    int rcnt = 0;

                    while (lv == v[l])
                    {
                        l++;
                        lcnt++;
                    }

                    while (rv == v[r])
                    {
                        r--;
                        rcnt++;
                    }

                    res += lcnt * rcnt;
                }
            }
            else if (v[l] + v[r] < need)
            {
                l++;
            }
            else if (v[l] + v[r] > need)
            {
                r--;
            }
        }
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}



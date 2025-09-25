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
        정렬 후
        투 포인터 양끝 좁히기
        l++ -> v[l] + v[r] 증가
        r-- -> v[l] + v[r] 감소
    */

    using T = tuple<int, int, int>;
    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int res = 0;
    for (int i = 0; i < N; i++)
    {
        int cur = v[i];

        int l = 0;
        int r = N - 1;

        while (l < r)
        {
            if (l == i)
            {
                l++;
                continue;
            }

            if (r == i)
            {
                r--;
                continue;
            }

            if (v[l] + v[r] == cur)
            {
                res++;
                break;
            }
            else if (v[l] + v[r] < cur)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}

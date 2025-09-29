#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1000001];
int lis[1000001];
int pre[1000001]; // pre[i] : i를 끝으로 하는 최대 길이의 수열에서 i 앞에 오는
                  // 요소

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

    cin >> N;
    int LMT = N + 1;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        pre[i] = i;
    }

    fill(lis, lis + N, LMT);

    auto check = [&](int idx, int cur) { return arr[idx] >= cur; };

    for (int i = 0; i < N; i++)
    {
        int cur = arr[i];

        auto it = lower_bound(lis, lis + N, LMT);
        int r = it - lis - 1;
        int l = 0;

        while (l <= r)
        {
            int m = (l + r) / 2;
            if (check(lis[m], cur))
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        int tidx = l;
        lis[tidx] = i;

        pre[i] = tidx == 0 ? i : lis[tidx - 1];
    }

    int res = lower_bound(lis, lis + N, LMT) - lis;

    cout << res << '\n';

    vector<int> history;
    int p = lis[res - 1];

    while (1)
    {
        history.push_back(p);
        if (pre[p] == p)
            break;
        p = pre[p];
    }

    reverse(history.begin(), history.end());
    for (int idx : history)
        cout << arr[idx] << ' ';
    cout << '\n';

    // inputFileStream.close();
    return 0;
}

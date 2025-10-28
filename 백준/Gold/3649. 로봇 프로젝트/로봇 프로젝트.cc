#include <bits/stdc++.h>
using namespace std;
const int NMX = 1000000;
int X, N;
int lego[NMX];

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

    while (cin >> X >> N)
    {
        X *= 10000000; // cm -> nm
        for (int i = 0; i < N; i++)
            cin >> lego[i];

        sort(lego, lego + N);

        int mx_diff = -1;
        pair<int, int> ans;
        for (int i = 0; i < N - 1; i++)
        {
            int need = X - lego[i];

            int lbi = lower_bound(lego + i + 1, lego + N, need) - lego;

            if (lbi < N && lego[lbi] + lego[i] == X &&
                mx_diff < lego[lbi] - lego[i])
            {
                mx_diff = lego[lbi] - lego[i];
                ans = {lego[i], lego[lbi]};
            }
        }

        if (mx_diff == -1)
            cout << "danger" << '\n';
        else
            cout << "yes " << ans.first << ' ' << ans.second << '\n';
    }

    // inputFileStream.close();
    return 0;
}
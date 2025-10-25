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

    int M, N;
    cin >> M >> N;

    vector<vector<int>> v(M, vector<int>(N));

    vector<vector<int>> vr(M, vector<int>(N));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
        }

        vector<int> cvi = v[i];
        sort(cvi.begin(), cvi.end());
        cvi.erase(unique(cvi.begin(), cvi.end()), cvi.end());

        for (int j = 0; j < N; j++)
        {
            vr[i][j] = lower_bound(cvi.begin(), cvi.end(), v[i][j]) - cvi.begin();
        }
    }

    sort(vr.begin(), vr.end());

    int res = 0;
    for (int i = 0; i < M;)
    {
        auto it = upper_bound(vr.begin(), vr.end(), vr[i]);
        auto idx = distance(vr.begin(), it);

        if (idx - i >= 2)
        {
            res += (idx - i) * (idx - i - 1) / 2;
        }

        // cout << i << ' ' << idx << '\n';
        i = idx;
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}


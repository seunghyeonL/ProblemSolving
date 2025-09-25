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

    int N, K;
    cin >> N >> K;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    int res = 1e9;
    for (int l = 0, r = 0, rionCnt = 0; l < N; l++)
    {
        while (r < N && rionCnt < K)
        {
            if (v[r] == 1)
            {
                rionCnt++;
            }
            r++;
        }

        if (rionCnt == K)
        {
            res = min(res, r - l);
        }

        if (v[l] == 1)
            rionCnt--;
    }

    cout << (res == 1e9 ? -1 : res) << '\n';

    // inputFileStream.close();
    return 0;
}
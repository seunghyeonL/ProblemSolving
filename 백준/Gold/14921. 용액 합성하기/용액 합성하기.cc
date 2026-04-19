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

    int mn = 2 * 1e9;
    int res{};
    for (int i = 0; i < N - 1; i++)
    {
        auto it = lower_bound(v.begin() + i + 1, v.end(), -v[i]);

        if (it != v.end())
        {
            if (mn >= abs(*it + v[i]))
            {
                mn = abs(*it + v[i]);
                res = *it + v[i];
            }
        }

        if (it != v.begin() + i + 1)
        {
            if (mn >= abs(*(it - 1) + v[i]))
            {
                mn = abs(*(it - 1) + v[i]);
                res = *(it - 1) + v[i];
            }
        }
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}

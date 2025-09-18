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
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int mn = 1e9;
    for (int i = 0; i < N - 3; i++)
    {
        for (int j = i + 3; j < N; j++)
        {
            int S1 = v[i] + v[j];
            int l = i + 1;
            int r = j - 1;
            while (l < r)
            {
                // l을 늘리면 커지고 r을 줄이면 줄어듬
                int S2 = v[l] + v[r];

                mn = min(mn, abs(S2 - S1));

                if (S2 < S1)
                    l++;
                else
                    r--;
            }
        }
    }

    cout << mn;

    // inputFileStream.close();
    return 0;
}

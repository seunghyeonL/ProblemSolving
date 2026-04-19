#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int R, C;
    cin >> R >> C;

    vector<int> d_kn[55];

    for (int i = 0; i < R; i++)
    {
        string str;
        cin >> str;

        int kn = 0;
        int d = 0;
        for (int j = C - 1; j >= 0; j--)
        {
            if ('1' <= str[j] && str[j] <= '9')
            {
                kn = str[j] - '0';
                d = C - 1 - j;
                break;
            }
        }

        if (kn)
        {
            d_kn[d].push_back(kn);
        }
    }

    vector<int> rank(10);
    for (int i = 0, r = 1; i <= 50; i++)
    {
        if (d_kn[i].empty())
            continue;

        for (int kn : d_kn[i])
        {
            rank[kn] = r;
        }

        r++;
    }

    for (int i = 1; i <= 9; i++)
        cout << rank[i] << '\n';

    // inputFileStream.close();
    return 0;
}

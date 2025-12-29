#include <bits/stdc++.h>
using namespace std;    

int get_mx_sum(vector<int> nca, vector<int> ncb)
{
    int l = 1, r = 99;
    int ret = 0;
    while (r > 0 && l < 100)
    {
        while (l < 100 && nca[l] == 0)
            ++l;
        while (r > 0 && ncb[r] == 0)
            --r;

        if (r > 0 && l < 100)
        {
            ret = max(ret, l + r);
            int mn = min(nca[l], ncb[r]);
            nca[l] -= mn;
            ncb[r] -= mn;
        }
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int N;
    vector<int> nca(100);
    vector<int> ncb(100);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int an, bn;
        cin >> an >> bn;
        nca[an]++;
        ncb[bn]++;

        cout << get_mx_sum(nca, ncb) << '\n';
    }

    // inputFileStream.close();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
int N, Q;
pair<int, int> menu[NMX];
vector<int> ST[4 * NMX];

void init_ST(int s, int e, int cv)
{
    if (s == e)
    {
        ST[cv].push_back(menu[s].second);
        return;
    }

    int m = (s + e) / 2;
    init_ST(s, m, 2 * cv);
    init_ST(m + 1, e, 2 * cv + 1);

    ST[cv].resize(ST[2 * cv].size() + ST[2 * cv + 1].size());

    merge(ST[2 * cv].begin(), ST[2 * cv].end(), ST[2 * cv + 1].begin(),
          ST[2 * cv + 1].end(), ST[cv].begin());
}

int find_range(int s, int e, int cv, int l, int r, int x, int y)
{
    if (r < s || e < l)
        return 0;

    if (l <= s && e <= r)
    {
        auto lb = lower_bound(ST[cv].begin(), ST[cv].end(), x);
        auto ub = upper_bound(ST[cv].begin(), ST[cv].end(), y);

        return ub - lb;
    }

    int m = (s + e) / 2;
    return find_range(s, m, 2 * cv, l, r, x, y) +
           find_range(m + 1, e, 2 * cv + 1, l, r, x, y);
};

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

    cin >> N >> Q;
    for (int i = 0; i < N; i++)
    {
        cin >> menu[i].first;
        cin >> menu[i].second;
    }

    sort(menu, menu + N);

    init_ST(0, N - 1, 1);

    // for (int i = 1; i <= 4 * N; i++)
    // {
    //     Printc<vector<int>>()(ST[i]);
    // }

    for (int i = 0; i < Q; i++)
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;

        int l = partition_point(menu, menu + N,
                                [u](const auto &el) { return el.first < u; }) -
                menu;
        int r = partition_point(menu, menu + N,
                                [v](const auto &el) { return el.first <= v; }) -
                menu;

        r--;

        cout << find_range(0, N - 1, 1, l, r, x, y) << '\n';
    }

    // inputFileStream.close();
    return 0;
}
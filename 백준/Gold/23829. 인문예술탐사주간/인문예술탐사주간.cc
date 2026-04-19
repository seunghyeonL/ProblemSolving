#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int NMX = 100000;
int N, Q;
int trees[NMX];
ll pf_sum[NMX + 1];

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
        cin >> trees[i];

    sort(trees, trees + N);

    for (int i = 1; i <= N; i++)
        pf_sum[i] = pf_sum[i - 1] + trees[i - 1];

    for (int i = 0; i < Q; i++)
    {
        int x;
        cin >> x;

        int ub = upper_bound(trees, trees + N, x) - trees;

        ll l_score = (ll)ub * x - pf_sum[ub];
        ll r_score = pf_sum[N] - pf_sum[ub] - (ll)(N - ub) * x;

        cout << l_score + r_score << '\n';
    }

    // inputFileStream.close();
    return 0;
}
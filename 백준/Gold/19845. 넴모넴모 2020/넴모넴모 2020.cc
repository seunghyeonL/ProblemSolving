#include <bits/stdc++.h>
using namespace std;

const int NMX = 250000;
int N, Q;
int A[NMX + 1];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        x : 가로, y : 세로, 1-base
     */

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 0; i < Q; i++)
    {
        int x, y;
        cin >> x >> y;

        int x_kill = max(0, A[y] - x + 1);
        int y_ub = upper_bound(A + 1, A + N + 1, x, greater<int>()) - A;
        // int y_lb = lower_bound(A + 1, A + N + 1, x, greater<int>()) - A;
        int y_kill = max(0, y_ub - y);

        // cout << x << ' ' << y << ' ' << x_kill << ' ' << y_kill << '\n';

        cout << max(0, x_kill + y_kill - 1) << '\n';
    }

    // inputFileStream.close();
    return 0;
}
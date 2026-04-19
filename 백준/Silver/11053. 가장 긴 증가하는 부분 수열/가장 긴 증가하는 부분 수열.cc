#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     */

    int N;
    cin >> N;

    int v[1001];
    for (int i = 0; i < N; i++)
        cin >> v[i];

    int INF = 1e9;
    int lis[1001];
    fill(lis, lis + 1001, INF);

    for (int i = 0; i < N; i++)
    {
        auto it = lower_bound(lis, lis + N, v[i]);

        *it = v[i];
    }

    cout << lower_bound(lis, lis + N, INF) - lis << '\n';

    // inputFileStream.close();
    return 0;
}


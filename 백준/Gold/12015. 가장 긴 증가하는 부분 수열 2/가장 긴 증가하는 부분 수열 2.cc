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
        LIS
    */

    int N;
    cin >> N;
    int INF = 1e9;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    vector<int> lis(N, INF);

    for (int el : v)
    {
        auto it = lower_bound(lis.begin(), lis.end(), el);
        *it = el;
    }

    cout << lower_bound(lis.begin(), lis.end(), INF) - lis.begin() << '\n';

    // inputFileStream.close();
    return 0;
}
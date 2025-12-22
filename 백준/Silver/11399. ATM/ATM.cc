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

    vector<int> P(N);
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }

    sort(P.begin(), P.end());

    vector<int> ps(N + 1);
    ps[0] = 0;

    for (int i = 1; i <= N; i++)
    {
        ps[i] = ps[i - 1] + P[i - 1];
    }

    cout << accumulate(ps.begin(), ps.end(), 0) << '\n';

    // inputFileStream.close();
    return 0;
}
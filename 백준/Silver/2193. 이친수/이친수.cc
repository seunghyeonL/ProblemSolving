#include <bits/stdc++.h>
using namespace std;

int N;

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

    cin >> N;
    vector<long long> dp0(N + 1);
    vector<long long> dp1(N + 1);

    /*
        dp1[i] = dp0[i - 1];
        dp0[i] = dp1[i - 1] + dp0[i - 1];
    */

    dp0[1] = 0;
    dp1[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        dp1[i] = dp0[i - 1];
        dp0[i] = dp0[i - 1] + dp1[i - 1];
    }

    cout << dp0[N] + dp1[N] << '\n';

    // inputFileStream.close();
    return 0;
}
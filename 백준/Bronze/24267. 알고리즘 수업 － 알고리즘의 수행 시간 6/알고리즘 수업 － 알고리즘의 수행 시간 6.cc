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

    long long N;
    cin >> N;

    /*
        i == 0
        1 + 2 + ... + N - 1
        N * (N - 1) / 2

        i == 1
        1 + 2 + ... + N - 2
        (N - 1) * (N - 2) / 2

        i -> (N - i) * (N - i - 1) / 2
    */

    long long ans = 0;
    for (int i = 1; i <= N - 2; i++)
        ans += (N - i) * (N - i - 1) / 2;

    cout << ans << '\n';
    cout << 3 << '\n';

    // inputFileStream.close();
    return 0;
}
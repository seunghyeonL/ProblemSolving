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

    int N, M;
    cin >> N >> M;

    string ans;
    int d = 1;
    while ((long long)d * M <= N)
        d *= M;

    while (d > 0)
    {
        int n = N / d;

        char c;
        if (n >= 0 && n <= 9)
            c = '0' + n;
        else
            c = 'A' + n - 10;

        ans.push_back(c);

        N %= d;
        d /= M;
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
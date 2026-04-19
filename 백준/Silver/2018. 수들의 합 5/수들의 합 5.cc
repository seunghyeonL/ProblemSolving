#include <bits/stdc++.h>
using namespace std;

const int NMX = 10000000;
int N;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;

    int ans = 0;

    for (int l = 1, r = 1, sum = 0; l <= N; l++)
    {
        while (r <= N && sum + r <= N)
        {
            sum += r++;
        }

        if (sum == N)
            ans++;

        sum -= l;
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
int N;
int X[NMX], Y[NMX];

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
    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
        cin >> Y[i];
    }

    sort(X, X + N);
    sort(Y, Y + N);

    int tx = X[N / 2];
    int ty = Y[N / 2];

    long long ans = 0;

    for (int i = 0; i < N; i++)
    {
        ans += abs(X[i] - tx) + abs(Y[i] - ty);
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
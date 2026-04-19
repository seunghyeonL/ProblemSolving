#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
int N, K;
int arr[NMX];
int ps[NMX + 1];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    ps[0] = 0;
    for (int i = 1; i <= N; i++)
        ps[i] = ps[i - 1] + arr[i - 1];

    int ans = -1e9;
    for (int i = 0; i < N - K + 1; i++)
    {
        ans = max(ans, ps[i + K] - ps[i]);
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
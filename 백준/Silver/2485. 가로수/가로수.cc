#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
int N;
int arr[NMX];
int D[NMX];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 1; i < N; i++)
        D[i] = arr[i] - arr[i - 1];

    int g = D[1];
    for (int i = 2; i < N; i++)
        g = gcd(g, D[i]);

    int ans = 0;

    for (int i = 1; i < N; i++)
        ans += D[i] / g - 1;

    cout << ans;

    // inputFileStream.close();
    return 0;
}
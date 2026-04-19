#include <bits/stdc++.h>
using namespace std;

const int NMX = 10000;
int N;
long long arr[NMX];

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

    sort(arr, arr + N);

    long long ans = 0;
    ans *= 2;
    int l = 0, r = N - 1;
    if (N % 2 == 1)
    {
        ans = arr[r--];
    }

    while (l < r)
    {
        ans = max(ans, arr[l++] + arr[r--]);
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
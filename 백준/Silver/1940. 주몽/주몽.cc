#include <bits/stdc++.h>
using namespace std;

const int NMX = 10000000;
int N, M;
int arr[NMX];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    int ans = 0;

    for (int i = 0; i < N - 1; i++)
    {
        int need = M - arr[i];

        auto [lb, rb] = equal_range(arr + i + 1, arr + N, need);

        ans += rb - lb;
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
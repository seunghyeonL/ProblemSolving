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

    constexpr int INF = 1e9;
    int N;
    cin >> N;
    vector<int> arr(2 * N);
    for (int i = 0; i < 2 * N; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    
    int ans = INF;
    for (int i = 0; i < N; i++)
        ans = min(ans, arr[i] + arr[2 * N - 1 - i]);

    cout << ans;

    // inputFileStream.close();
    return 0;
}

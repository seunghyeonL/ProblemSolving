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

    // 책 챙겨서 갈때 최대한 챙겨서 제일 먼쪽부터 채우기

    int N, M;
    cin >> N >> M;

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int ans = 0;
    for (int i = N - 1; i >= 0 && arr[i] > 0; i -= M)
    {
        ans += 2 * arr[i];
    }

    for (int i = 0; i < N && arr[i] < 0; i += M)
    {
        ans -= 2 * arr[i];
    }

    ans -= max(abs(arr[0]), abs(arr[N - 1]));

    cout << ans << '\n';

    // inputFileStream.close();
    return 0;
}

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

    int N;
    cin >> N;

    vector<long long> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    if (N == 1)
    {
        cout << arr[0] << '\n';
        return 0;
    }

    sort(arr.begin(), arr.end());

    long long ans = 0;

    int l = 0;
    // 음수는 두개씩 곱해서 더하고 그게 안되면 0이랑 곱해서 더하기
    while (l + 1 < N && arr[l + 1] <= 0)
    {
        ans += arr[l] * arr[l + 1];
        l += 2;
    }

    while (l < N && arr[l] <= 1)
    {
        ans += arr[l];
        l++;
    }

    // l : arr[l] > 1 인 최소 idx

    int r = N - 1;
    while (r - 1 >= l)
    {
        ans += arr[r] * arr[r - 1];
        r -= 2;
    }

    if (l == r)
        ans += arr[r];

    cout << ans;

    // inputFileStream.close();
    return 0;
}
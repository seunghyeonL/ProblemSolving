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

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int ans = 0;
    int l = 0, r = N - 1;
    while (l < r)
    {
        ++ans, --r;

        if (--arr[l] == 0)
            ++l;
    }

    cout << ans << '\n';

    // inputFileStream.close();
    return 0;
}

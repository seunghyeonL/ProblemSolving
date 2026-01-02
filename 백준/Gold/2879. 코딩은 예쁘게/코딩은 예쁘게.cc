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

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        arr[i] = n - arr[i];
    }

    int ans = 0;
    for (int l = 0; l < N; l++)
    {
        while (arr[l] != 0)
        {
            int r = l;
            while (r < N && arr[l] * arr[r] > 0)
                r++;

            int sgn = (arr[l] > 0) - (arr[l] < 0);
            for (int i = l; i < r; i++)
            {
                arr[i] -= sgn;
            }

            ans++;
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000;
int N;
int arr[NMX];
vector<int> dp1; // dp1[i] : [0, i] 범위의 LIS
vector<int> dp2; // dp2[i] : [i, N) 범위의 LDS

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

    dp1.resize(N, 1);
    dp2.resize(N, 1);

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                dp1[i] = max(dp1[i], dp1[j] + 1);
        }
    }

    for (int i = N - 2; i >= 0; i--)
    {
        for (int j = N - 1; j > i; j--)
        {
            if (arr[j] < arr[i])
                dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
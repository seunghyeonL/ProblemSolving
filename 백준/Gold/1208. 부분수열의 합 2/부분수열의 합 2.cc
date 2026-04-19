#include <bits/stdc++.h>
using namespace std;

const int NMX = 40;
int N, S;
int arr[NMX];
vector<int> ps1;
vector<int> ps2;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
     */

    cin >> N >> S;
    int half = N / 2;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int mask = 0; mask < 1 << half; mask++)
    {
        int sum = 0;
        for (int i = 0; i < half; i++)
        {
            if (mask >> i & 1)
            {
                sum += arr[i];
            }
        }

        ps1.push_back(sum);
    }

    for (int mask = 0; mask < 1 << (N - half); mask++)
    {
        int sum = 0;
        for (int i = 0; i < N - half; i++)
        {
            if (mask >> i & 1)
            {
                sum += arr[half + i];
            }
        }

        ps2.push_back(sum);
    }

    sort(ps2.begin(), ps2.end());
    long long ans = 0;
    for (int sum1 : ps1)
    {
        int need = S - sum1;

        auto [it1, it2] = equal_range(ps2.begin(), ps2.end(), need);

        ans += (it2 - it1);
    }

    if (S == 0)
        ans--;

    cout << ans;

    // inputFileStream.close();
    return 0;
}
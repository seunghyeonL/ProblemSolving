#include <bits/stdc++.h>
using namespace std;

const int NMX = 5000;
int N, C;
int arr[NMX];

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

    cin >> N >> C;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    // 1개
    if (binary_search(arr, arr + N, C))
    {
        cout << 1;
        return 0;
    }

    bool found = false;

    // 2개
    for (int i = 0; i < N - 1 && !found; i++)
    {
        int lb = lower_bound(arr + i + 1, arr + N, C - arr[i]) - arr;
        if (lb < N && arr[lb] + arr[i] == C)
            found = true;
    }

    if (found)
    {
        cout << 1;
        return 0;
    }

    // 3개
    for (int i = 0; i < N && !found; i++)
    {
        int need = C - arr[i];

        int l = 0, r = N - 1;

        while (l < r)
        {
            if (l == i)
            {
                l++;
                continue;
            }

            if (r == i)
            {
                r--;
                continue;
            }

            if (arr[l] + arr[r] < need)
                l++;
            else if (arr[l] + arr[r] > need)
                r--;
            else
            {
                found = true;
                break;
            }
        }
    }

    if (found)
    {
        cout << 1;
        return 0;
    }

    cout << 0;

    // inputFileStream.close();
    return 0;
}
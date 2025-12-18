#include <bits/stdc++.h>
using namespace std;

const int NMX = 5000;
int N, M;
int arr[NMX];

bool check(int mx_diff)
{
    int cnt = 1;
    int mx = arr[0];
    int mn = arr[0];
    for (int i = 1; i < N; i++)
    {
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);

        if (mx - mn > mx_diff)
        {
            cnt++;
            mx = arr[i];
            mn = arr[i];
        }
    }

    return cnt <= M;
}

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

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    // 구간점수 최댓값을 매개변수 탐색
    int l = 0, r = 10000;
    while (l <= r)
    {
        int m = (l + r) / 2;

        if (check(m))
            r = m - 1;
        else
            l = m + 1;
    }

    cout << l;

    // inputFileStream.close();
    return 0;
}
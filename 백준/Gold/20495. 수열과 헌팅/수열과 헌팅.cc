#include <bits/stdc++.h>
using namespace std;

const int NMX = 500000;
int N;
pair<int, int> arr[NMX];
int L[NMX];
int R[NMX];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        나머지 원소들이 최소이고 내가 최대일때 위치가 최대 idx
        나머지 원소들이 최대이고 내가 최소일때 위치가 최소 idx
     */

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int m, d;
        cin >> m >> d;

        int l = m - d;
        int r = m + d;

        arr[i] = {l, r};
        L[i] = l;
        R[i] = r;
    }

    sort(L, L + N);
    sort(R, R + N);

    for (int i = 0; i < N; i++)
    {
        auto [l, r] = arr[i];

        // 자기 자신의 최소값 하나 빼주기
        int mx = upper_bound(L, L + N, r) - L - 1;
        int mn = lower_bound(R, R + N, l) - R;

        // 1 - base
        cout << mn + 1 << ' ' << mx + 1 << '\n';
    }

    // inputFileStream.close();
    return 0;
}
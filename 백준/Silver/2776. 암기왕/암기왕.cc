#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000000;
int N, M;

int arr1[NMX];
int arr2[NMX];

void solve()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr1[i];

    cin >> M;
    for (int i = 0; i < M; i++)
        cin >> arr2[i];

    sort(arr1, arr1 + N);

    for (int i = 0; i < M; i++)
        cout << binary_search(arr1, arr1 + N, arr2[i]) << '\n';
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

    int T;
    cin >> T;

    while (--T >= 0)
        solve();

    // inputFileStream.close();
    return 0;
}
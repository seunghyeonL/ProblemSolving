#include <bits/stdc++.h>
using namespace std;

const int NMX = 20000;
int N;
string arr[NMX];

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

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N, [](const auto &a, const auto &b)
         { return a.size() == b.size() ? a < b : a.size() < b.size(); });

    int idx_end = unique(arr, arr + N) - arr;

    for (int i = 0; i < idx_end; i++)
        cout << arr[i] << '\n';

    // inputFileStream.close();
    return 0;
}
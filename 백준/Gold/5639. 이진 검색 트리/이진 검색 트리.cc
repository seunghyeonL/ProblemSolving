#include <bits/stdc++.h>
using namespace std;

constexpr int NMX = 10000;
constexpr int LMT = 1000000;
int N;
int arr[NMX];
int idx = 0;

void rec(int mn, int mx)
{
    if (idx >= N)
        return;

    int root = arr[idx];

    if (arr[idx] < mn || arr[idx] > mx)
        return;

    idx++;

    rec(mn, root - 1);
    rec(root + 1, mx);

    cout << root << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int n;
    while (cin >> n)
        arr[N++] = n;

    rec(-LMT, LMT);

    // inputFileStream.close();
    return 0;
}
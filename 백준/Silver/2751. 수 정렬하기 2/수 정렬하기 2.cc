#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000000;
int N;
int arr[NMX];
int tmp[NMX];

void merge_sort(int s, int e)
{
    if (s + 1 >= e)
        return;

    int m = (s + e) / 2;
    merge_sort(s, m);
    merge_sort(m, e);

    merge(arr + s, arr + m, arr + m, arr + e, tmp + s);
    copy(tmp + s, tmp + e, arr + s);
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

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    merge_sort(0, N);

    for (int i = 0; i < N; i++)
        cout << arr[i] << '\n';

    // inputFileStream.close();
    return 0;
}
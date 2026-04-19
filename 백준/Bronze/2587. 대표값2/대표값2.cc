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

    /*
     */

    int arr[5];
    for (int i = 0; i < 5; i++)
        cin >> arr[i];

    sort(arr, arr + 5);

    cout << accumulate(arr, arr + 5, 0) / 5 << '\n';
    cout << arr[2];

    // inputFileStream.close();
    return 0;
}
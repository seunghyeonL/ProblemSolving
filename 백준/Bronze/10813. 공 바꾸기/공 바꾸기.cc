#include <bits/stdc++.h>
using namespace std;


const int MX = 100;
int N, M;
int arr[MX + 1];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        arr[i] = i;
    }

    while (--M >= 0)
    {
        int i, j;
        cin >> i >> j;

        swap(arr[i], arr[j]);
    }

    for (int i = 1; i <= N; i++)
    {
        cout << arr[i] << ' ';
    }

    // inputFileStream.close();
    return 0;
}
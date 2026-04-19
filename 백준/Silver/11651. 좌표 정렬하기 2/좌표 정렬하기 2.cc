#include <bits/stdc++.h>
using namespace std;

const int NMX = 100000;
int N;
pair<int, int> arr[NMX];

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
    {
        int x, y;
        cin >> x >> y;

        arr[i] = {x, y};
    }

    sort(arr, arr + N,
         [](const auto &a, const auto &b)
         {
             auto [xa, ya] = a;
             auto [xb, yb] = b;

             return (ya == yb ? xa < xb : ya < yb);
         });

    for (int i = 0; i < N; i++)
    {
        auto [x, y] = arr[i];

        cout << x << ' ' << y << '\n';
    }

    // inputFileStream.close();
    return 0;
}
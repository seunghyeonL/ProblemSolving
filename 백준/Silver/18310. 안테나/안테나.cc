#include <bits/stdc++.h>
using namespace std;

const int NMX = 200000;
int N;
int house[NMX];

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
        cin >> house[i];

    sort(house, house + N);

    int l = 0, r = N - 1;

    while (l < r)
    {
        l++;
        r--;
    }

    cout << house[r];

    // inputFileStream.close();
    return 0;
}
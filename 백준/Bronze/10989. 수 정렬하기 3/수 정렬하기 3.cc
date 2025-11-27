#include <bits/stdc++.h>
using namespace std;

const int NMX = 10000000;
const int LMT = 10000;
int N;
int freq[LMT + 1];

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
        int n;
        cin >> n;
        freq[n]++;
    }

    vector<pair<int, int>> arr; // 숫자, 빈도
    for (int i = 1; i <= LMT; i++)
    {
        if (freq[i])
            arr.emplace_back(i, freq[i]);
    }

    sort(arr.begin(), arr.end());

    for (auto [n, f] : arr)
    {
        while (f-- > 0)
            cout << n << '\n';
    }

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;    

const int NMX = 500000;
int N;
int arr[NMX];
unordered_map<int, int> um;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;

        sum += n;
        arr[i] = n;
        um[n]++;
    }

    sort(arr, arr + N);

    vector<pair<int, int>> arr1(um.begin(), um.end());
    sort(arr1.begin(), arr1.end(),
         [](const auto &a, const auto &b)
         {
             auto [val_a, freq_a] = a;
             auto [val_b, freq_b] = b;

             return (freq_a == freq_b ? val_a > val_b : freq_a < freq_b);
         });

    auto it = arr1.end();
    auto [mx_freq_val, mx_freq] = *(--it);
    if (it != arr1.begin() && (--it)->second == mx_freq)
        mx_freq_val = it->first;

    cout << int(round((double)sum / N)) << '\n';
    cout << arr[N / 2] << '\n';
    cout << mx_freq_val << '\n';
    cout << arr[N - 1] - arr[0] << '\n';

    // inputFileStream.close();
    return 0;
}
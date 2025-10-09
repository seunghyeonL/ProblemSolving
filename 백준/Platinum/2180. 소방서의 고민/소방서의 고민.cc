#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> fireInfo;

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
        int a, b;
        cin >> a >> b;
        fireInfo.emplace_back(a, b);
    }

    partition(fireInfo.begin(), fireInfo.end(),
              [](const auto el) { return el.first > 0; });

    auto zeroStart =
        partition_point(fireInfo.begin(), fireInfo.end(),
                        [](const auto el) { return el.first > 0; });

    sort(fireInfo.begin(), zeroStart,
         [](const auto &x1, const auto &x2)
         {
             auto [a1, b1] = x1;
             auto [a2, b2] = x2;

             return float(b1) / a1 < float(b2) / a2;
         });

    long long t = 0;
    for (auto [a, b] : fireInfo)
    {
        t += a * t + b;
        t %= 40000;
    }

    cout << t << '\n';

    // inputFileStream.close();
    return 0;
}
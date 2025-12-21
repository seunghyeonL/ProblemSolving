#include <bits/stdc++.h>
using namespace std;

const int LMT = 100000;
int N;
vector<pair<int, int>> trees; // dh, ch

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;
    trees.resize(N);

    for (int i = 0; i < N; i++)
        cin >> trees[i].second;

    for (int i = 0; i < N; i++)
        cin >> trees[i].first;

    sort(trees.begin(), trees.end());

    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        auto [dh, ch] = trees[i];
        ans += ch + i * dh;
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
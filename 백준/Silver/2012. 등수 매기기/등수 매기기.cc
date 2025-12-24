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

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    long long ans = 0;
    for (int i = 0; i < N; i++)
        ans += abs((i + 1) - v[i]);

    cout << ans << '\n';

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin >> N;

    vector<int> num(N);

    for (int i = 0; i < N; i++)
        cin >> num[i];

    long long answer = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            answer += gcd(num[i], num[j]);
        }
    }

    cout << answer << '\n';
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
        solve();

    // ifstream inputFileStream("input.txt");

    // inputFileStream.close();
    return 0;
}
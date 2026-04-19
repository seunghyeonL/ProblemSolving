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

    vector<int> ans(N);
    for (int i = 0; i < N; i++)
    {
        int n = (i / 2);
        if (i % 2 == 0)
            ans[i] = 1 + n;
        else
            ans[i] = N - n;
    }

    for (int n : ans)
        cout << n << ' ';

    // inputFileStream.close();
    return 0;
}
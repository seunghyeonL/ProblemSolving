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
    int m = N / 2;

    for (int i = 0, j = 1; i < N; i++)
    {
        if (i % 2 == 0)
            ans[i] = m + j;
        else
            ans[i] = j++;
    }

    for (int n : ans)
        cout << n << ' ';

    // inputFileStream.close();
    return 0;
}
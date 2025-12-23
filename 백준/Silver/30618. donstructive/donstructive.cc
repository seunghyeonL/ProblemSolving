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

    // 가운데 있을수록 더 많이 더해짐

    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 1, l = 0, r = N - 1; i <= N; i++)
    {
        if (i % 2 == 1)
            v[l++] = i;
        else
            v[r--] = i;
    }

    for (int el : v)
        cout << el << ' ';

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int N;
    cin >> N;

    vector<int> v(9);

    int cN = N;

    while (cN > 0)
    {
        v[cN % 10]++;
        cN /= 10;
    }

    int mx = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i != 6 && i != 9)
            mx = max(mx, v[i]);
    }

    mx = max(mx, (v[6] + v[9]) / 2 + (v[6] + v[9]) % 2);

    cout << mx << '\n';

    // inputFileStream.close();
    return 0;
}
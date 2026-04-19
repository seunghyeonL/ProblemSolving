#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;

int pow(int n, int p)
{
    int ret = 1;
    while (p-- > 0)
    {
        ret *= n;
    }
    return ret;
}

void rec(int s, int e)
{
    if (s + 1 == e)
        return;

    int d = (e - s) / 3;
    fill(arr.begin() + s + d, arr.begin() + e - d, 0);

    rec(s, s + d);
    rec(e - d, e);
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    while (cin >> N)
    {
        int sz = pow(3, N);
        arr.resize(sz);
        fill(arr.begin(), arr.end(), 1);

        rec(0, sz);

        for (int i = 0; i < sz; i++)
            cout << (arr[i] ? '-' : ' ');

        cout << '\n';
    }

    // inputFileStream.close();
    return 0;
}
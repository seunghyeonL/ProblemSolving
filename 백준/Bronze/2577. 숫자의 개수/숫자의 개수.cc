#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int A, B, C;
    cin >> A >> B >> C;

    int n = A * B * C;

    vector<int> v(10);
    while (n > 0)
    {
        v[n % 10]++;
        n /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << v[i] << '\n';
    }

    // inputFileStream.close();
    return 0;
}
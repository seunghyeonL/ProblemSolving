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

    int n = 2;

    for (int i = 1; i <= N; i++)
    {
        n = 2 * n - 1;
    }

    cout << n * n;

    // inputFileStream.close();
    return 0;
}
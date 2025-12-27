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

    int K;
    cin >> K;

    // K를 넘는 최소 2 거듭제곱수 필요

    int N = 1;
    int p = 0;
    while (N < K)
    {
        ++p;
        N *= 2;
    }

    int cnt_0 = 0;
    for (int i = 0; i < p; i++)
    {
        if ((K >> i) & 1)
            break;

        cnt_0++;
    }

    cout << N << ' ' << p - cnt_0 << '\n';

    // inputFileStream.close();
    return 0;
}

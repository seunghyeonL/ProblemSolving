#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        a^b % c 구하기
        매우 큰 수
        빠른 거듭제곱
    */

    long long a, b, c;
    cin >> a >> b >> c;

    long long res = 1;

    while (b > 0)
    {
        if (b % 2 == 1)
        {
            res = res * a % c;
        }

        a = a * a % c;

        b /= 2;
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

long long n, k;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        N번의 가위질로 만들 수 있는 개수
        N = a + b 일때 (a + 1) * (b + 1)개
        [0, N/2]범위에서 a를 증가시킬수록 (a + 1) * (b + 1)값이 단조 증가
        => 이분탐색
     */

    cin >> n >> k;

    int l = 0, r = n / 2;

    while (l <= r)
    {
        int m = (l + r) / 2;

        if ((m + 1) * (n - m + 1) <= k)
            l = m + 1;
        else
            r = m - 1;
    }

    if ((r + 1) * (n - r + 1) == k)
        cout << "YES";
    else
        cout << "NO";

    // inputFileStream.close();
    return 0;
}
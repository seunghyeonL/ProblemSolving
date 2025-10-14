#include <bits/stdc++.h>
using namespace std;

int N, K;

int power(int n, int p)
{
    int res = 1;
    while (p-- > 0)
    {
        res *= n;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        자릿수별로 묶어서 처리하기
     */

    // ifstream inputFileStream("input.txt");

    cin >> N >> K;

    int len = 1;       // 수 길아
    long long num = 9; // len 길이의 수 개수
    int cur = 1;

    while (K - num * len > 0)
    {
        cur += num;
        K -= num * len;
        len++;
        num *= 10;
    }

    int target = cur + (K - 1) / len;

    int ans = -1;
    if (target <= N)
    {
        ans = to_string(target)[(K - 1) % len] - '0';
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
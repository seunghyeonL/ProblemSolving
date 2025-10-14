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

    while (K - num * len > 0)
    {
        K -= num * len;
        len++;
        num *= 10;
    }

    int ans = -1;
    bool found = false;
    for (int i = power(10, len - 1); i <= N && !found; i++)
    {
        string si = to_string(i);

        for (int j = 0; j < len; j++)
        {
            // cout << si[j];
            if (--K == 0)
            {
                ans = si[j] - '0';
                found = true;
                break;
            }
        }
        // cout << '\n';
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
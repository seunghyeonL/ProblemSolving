#include <bits/stdc++.h>
using namespace std;

/*
    최대 길이를 len로 잡았을때 가능, 불가능 여부를 이분탐색(어느 수치 이상은
   항상 불가능, 그 이전은 가능)

    첫 위치에 심판을 배치하고
    l이상의 거리가 되도록 다음 심판을 배치.

    심판 수가 M 이상이면 가능(중간 심판을 없애주면 M명의 심판으로 가능)
    M미만이면 불가능

    심판 배치가 필요하므로 M 이상의 심판은 0으로 배치
*/

const int NMX = 1000000;
const int KMX = 50;
int N, M, K;
int arr[KMX];
string his[NMX + 1];

bool check(int len)
{
    int n = 1;
    int cx = arr[0];
    his[len].push_back('1');

    for (int i = 1; i < K; i++)
    {
        if (n == M)
        {
            his[len].push_back('0');
            continue;
        }

        int nx = arr[i];
        if (nx - cx >= len)
        {
            n++;
            cx = nx;
            his[len].push_back('1');
        }
        else
            his[len].push_back('0');
    }

    if (n == M)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N >> M >> K;

    for (int i = 0; i < K; i++)
        cin >> arr[i];

    int l = 1, r = 1000000;
    while (l <= r)
    {
        int m = (l + r) / 2;

        if (check(m))
            l = m + 1;
        else
            r = m - 1;
    }

    cout << his[r] << '\n';

    // inputFileStream.close();
    return 0;
}

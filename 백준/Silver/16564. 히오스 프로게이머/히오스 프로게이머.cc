#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000000;
int N, K;
long long levels[NMX];

// 최소 요소를 m으로 만들 수 있는가?
bool check(long long m)
{
    long long point = K;
    for (int i = 0; i < N; i++)
    {
        point -= max(0LL, m - levels[i]);
        if (point < 0)
            return false;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        최소 요소를 최대로
        특정 값 k 이하는 최소 요소로 가능
        k 초과는 불가

        => 이분탐색
    */

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> levels[i];

    long long l = *min_element(levels, levels + N);
    long long r = 2 * 1e9;

    while (l <= r)
    {
        long long m = (l + r) / 2;

        if (check(m))
            l = m + 1;
        else
            r = m - 1;
    }

    cout << r;

    // inputFileStream.close();
    return 0;
}
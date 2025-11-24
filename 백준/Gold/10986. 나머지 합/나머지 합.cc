#include <bits/stdc++.h>
using namespace std;

const int NMX = 1000000;
const int MMX = 1000;
int N, M;
int arr[NMX];
int P[NMX + 1];
long long cnt[MMX];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        i <= j
        sum[i, j] == 0 (mod M)
        P[j + 1] - P[i] == 0 (mod M)
        P[j + 1] == P[i] (mod M)

        => i < j && P[i] == P[j] 인 {i, j} 개수 찾기
    */

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        arr[i] %= M;
    }

    for (int i = 1; i <= N; i++)
    {
        P[i] = P[i - 1] + arr[i - 1];
        P[i] %= M;
    }

    for (int i = 0; i <= N; i++)
        cnt[P[i]]++;

    long long ans = 0;
    for (int i = 0; i < M; i++)
    {
        long long n = cnt[i];

        ans += n * (n - 1) / 2;
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
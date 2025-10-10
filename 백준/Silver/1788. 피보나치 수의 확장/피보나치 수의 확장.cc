#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000000;
const int NMX = 1000000;
vector<long long> fibo(NMX + 1);
// fibo[n] = fibo[n - 1] + fibo[n - 2];
// fibio[n - 2] = fibo[n] - fibo[n - 1]
int N;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");
    cin >> N;

    fibo[0] = 0;
    fibo[1] = 1;

    if (N < 0)
    {
        for (int i = 2; i <= -N; i++)
        {
            fibo[i] = fibo[i - 2] - fibo[i - 1];
            int sign = fibo[i] < 0 ? -1 : 1;
            fibo[i] = (llabs(fibo[i]) % MOD) * sign;
        }
    }
    {
        for (int i = 2; i <= N; i++)
        {
            fibo[i] = (fibo[i - 2] + fibo[i - 1]) % MOD;
        }
    }

    int answer = fibo[abs(N)];
    cout << (answer == 0 ? 0 : (answer < 0 ? -1 : 1)) << '\n';
    cout << abs(answer) << '\n';

    // inputFileStream.close();
    return 0;
}
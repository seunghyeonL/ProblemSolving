#include <bits/stdc++.h>
using namespace std;

const int NMX = 4000000;
int N;
bool isPrime[NMX + 1];
vector<int> primes;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;
    fill(isPrime + 2, isPrime + N + 1, true);

    for (int i = 2; i <= N; i++)
    {
        if (!isPrime[i])
            continue;
        primes.push_back(i);

        for (long long j = (long long)i * i; j <= N; j += i)
        {
            isPrime[j] = false;
        }
    }

    int sz = primes.size();

    int ans = 0;
    for (int l = 0, r = 0, sum = 0; l < sz; l++)
    {
        while (r < sz && sum + primes[r] <= N)
        {
            sum += primes[r++];
        }

        if (sum == N)
            ans++;

        sum -= primes[l];
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}
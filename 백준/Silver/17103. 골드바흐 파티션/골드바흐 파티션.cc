#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int LMT = 1000000;
int T;
int N;
bool isPrime[LMT + 1];

void solve()
{
    cin >> N;

    int answer = 0;
    for (int i = 2; i <= N / 2; i++)
    {
        if (isPrime[i] && isPrime[N - i])
            answer++;
    }

    cout << answer << '\n';
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
     */

    fill(isPrime + 1, isPrime + 1 + LMT, true);
    
    isPrime[1] = false;
    for (int i = 2; i <= LMT; i++)
    {
        if (!isPrime[i])
            continue;

        for (ll j = (ll)i * i; j <= LMT; j += i)
        {
            isPrime[j] = false;
        }
    }

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve();
    }

    // inputFileStream.close();
    return 0;
}
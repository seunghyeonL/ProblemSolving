#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll A, B;

const int MAX = int(1e7);
bool isPrime[MAX + 1];

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
    cin >> A >> B;

    fill(isPrime + 1, isPrime + 1 + MAX, true);
    isPrime[1] = false;

    ll answer = 0;
    for (int i = 2; i <= MAX; i++)
    {
        if (!isPrime[i])
            continue;

        if (ll(i) * i > B)
            break;

        for (ll n = (ll)i * i; n <= B; n *= i)
        {
            if (n >= A)
                answer++;
            
            if (n > B / i)
                break;
        }

        for (ll j = (ll)i * i; j <= MAX; j += i)
        {
            isPrime[j] = false;
        }
    }

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}
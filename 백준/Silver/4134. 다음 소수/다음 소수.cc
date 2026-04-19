#include <bits/stdc++.h>
using namespace std;

long long N;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int T;
    cin >> T;
    while (T-- > 0)
    {
        cin >> N;

        if (N == 0 || N == 1)
        {
            cout << 2 << '\n';
            continue;
        }

        long long ans = N;

        while (true)
        {
            bool is_prime = true;
            for (long long i = 2; i <= ans / i; i++)
            {
                if (ans % i == 0)
                {
                    is_prime = false;
                    break;
                }
            }

            if (is_prime)
                break;

            ans++;
        }

        cout << ans << '\n';
    }

    // inputFileStream.close();
    return 0;
}
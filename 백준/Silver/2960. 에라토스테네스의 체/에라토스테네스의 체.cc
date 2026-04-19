#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    int N, K;
    cin >> N >> K;

    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    int answer = 0;
    int cnt = 0;
    for (int i = 2; i <= N; i++)
    {
        if (!isPrime[i])
            continue;

        if (++cnt == K)
        {
            answer = i;
            break;
        }

        bool finish = false;
        for (int n = i * i; n <= N; n += i)
        {
            if (!isPrime[n])
                continue;

            isPrime[n] = false;
            if (++cnt == K)
            {
                answer = n;
                finish = true;
                break;
            }
        }

        if (finish)
            break;
    }

    cout << answer << '\n';

    // inputFileStream.close();
    return 0;
}
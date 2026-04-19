#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    /*
        에라스토테네스 체
    */

    int M, N;
    cin >> M >> N;

    vector<bool> isPrime(N + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i <= N; i++)
    {
        if (!isPrime[i])
            continue;

        for (long long j = (long long)i * i; j <= N; j += i)
        {
            isPrime[j] = false;
        }
    }

    for (int i = M; i <= N; i++)
    {
        if (isPrime[i])
            cout << i << '\n';
    }

    // inputFileStream.close();
    return 0;
}


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

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    vector<bool> isPrime(1001, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i <= 1000; i++)
    {
        if (!isPrime[i])
            continue;

        for (int j = i * i; j <= 1000; j += i)
        {
            isPrime[j] = false;
        }
    }

    int res = 0;
    for (int n : v)
    {
        if (isPrime[n])
            res++;
    }

    cout << res << '\n';

    // inputFileStream.close();
    return 0;
}

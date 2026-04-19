#include <bits/stdc++.h>
using namespace std;
int N;

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

    cin >> N;
    vector<long long> fibo(N + 1);
    fibo[0] = 1;
    fibo[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    cout << fibo[N - 1] << '\n';

    // inputFileStream.close();
    return 0;
}
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
        이항계수
        nCk
    */

    int N, K;
    cin >> N >> K;

    vector<int> factorials(N + 1);
    factorials[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        factorials[i] = factorials[i - 1] * i;
    }

    cout << factorials[N] / (factorials[K] * factorials[N - K]) << '\n';

    // inputFileStream.close();
    return 0;
}
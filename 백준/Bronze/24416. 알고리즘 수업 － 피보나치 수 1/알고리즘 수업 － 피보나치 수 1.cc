#include <bits/stdc++.h>
using namespace std;

const int NMX = 40;
int N;
int fibo[NMX + 1];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;
    fibo[1] = fibo[2] = 1;

    for (int i = 3; i <= N; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];

    cout << fibo[N] << ' ' << N - 2;

    // inputFileStream.close();
    return 0;
}
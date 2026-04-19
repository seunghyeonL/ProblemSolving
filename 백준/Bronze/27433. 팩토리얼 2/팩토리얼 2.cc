#include <bits/stdc++.h>
using namespace std;

int N;

long long factorial(int n)
{
    if (n == 0)
        return 1;

    return (long long)n * factorial(n - 1);
}

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> N;

    cout << factorial(N);

    // inputFileStream.close();
    return 0;
}
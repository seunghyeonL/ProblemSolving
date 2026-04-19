#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    long long N;
    cin >> N;

    // 1 + 2 + ... + N - 1
    // N * (N - 1) / 2
    
    cout << N * (N - 1) / 2 << '\n';
    cout << 2 << '\n';
    

    // inputFileStream.close();
    return 0;
}
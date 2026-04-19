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

    int N;
    cin >> N;

    vector<int> fibo(N + 1);
    fibo[1] = 1;
    fibo[2] = 1;
    for (int i = 3; i <= N; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];

    int r = N % 3;

    vector<int> A;
    vector<int> B;

    if (r == 2)
    {
        A.push_back(1);
        B.push_back(2);
    }

    for (int i = 1 + r; i <= N; i += 3)
    {
        A.push_back(i);
        A.push_back(i + 1);
        B.push_back(i + 2);
    }

    cout << A.size() << '\n';
    for (int n : A)
        cout << n << ' ';
    cout << '\n';
    cout << B.size() << '\n';
    for (int n : B)
        cout << n << ' ';
    cout << '\n';

    // cout << '\n';
    // for (int n : A)
    //     cout << fibo[n] << ' ';
    // cout << '\n';
    // for (int n : B)
    //     cout << fibo[n] << ' ';
    // cout << '\n';
    
    // inputFileStream.close();
    return 0;
}
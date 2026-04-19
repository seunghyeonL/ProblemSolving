#include <bits/stdc++.h>
using namespace std;

long long A, B;

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> A >> B;
    cout << lcm(A, B);

    // inputFileStream.close();
    return 0;
}
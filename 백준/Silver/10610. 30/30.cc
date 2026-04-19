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

    /*
     */

    string N;
    cin >> N;

    sort(N.begin(), N.end(), greater<char>());

    bool impossible = false;
    if (N.back() != '0')
        impossible = true;
    else
    {
        int digitSum = 0;
        for (char c : N)
        {
            digitSum += (c - '0');
        }
        if (digitSum % 3 != 0)
            impossible = true;
    }

    cout << (impossible ? "-1" : N) << '\n';

    // inputFileStream.close();
    return 0;
}
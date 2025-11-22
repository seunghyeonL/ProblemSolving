#include <bits/stdc++.h>
using namespace std;

const int LMX = 1'000'000;
int L;
string str;
int F[LMX];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> L;
    cin >> str;

    for (int i = 1, j = 0; i < L; i++)
    {
        while (j > 0 && str[i] != str[j])
            j = F[j - 1];

        if (str[i] == str[j])
            F[i] = ++j;
    }

    cout << L - F[L - 1];

    // inputFileStream.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int SZMX = 200000;
string S, P;
int F[SZMX];

int main(int argc, char const *argv[])
{
    // #include <bits/stdc++.h>
    // using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ifstream inputFileStream("input.txt");

    cin >> S >> P;
    string origin;

    for (char c : S)
    {
        if (c < '0' || c > '9')
            origin.push_back(c);
    }

    int sz = origin.size();

    for (int i = 1, j = 0; i < sz; i++)
    {
        while (j > 0 && origin[i] != origin[j])
            j = F[j - 1];

        if (origin[i] == origin[j])
            F[i] = ++j;
    }

    int ans = 0;
    for (int i = 0, j = 0; i < sz; i++)
    {
        while (j > 0 && origin[i] != P[j])
            j = F[j - 1];

        if (origin[i] == P[j])
            j++;

        if (j == P.size())
        {
            ans = 1;
            break;
        }
    }

    cout << ans;

    // inputFileStream.close();
    return 0;
}